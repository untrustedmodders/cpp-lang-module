#!/usr/bin/python3
import argparse
import glob
import json
import os
import sys

from cxxheaderparser import simple


def convert_type(type: str):
    switch_dict = {
        'const char*': 'string',
        'char*': 'string',
        'const char**': 'string*',
        'char**': 'string*',
        'void': 'void',
        'bool': 'bool',
        'float': 'float',
        'double': 'double',
        'void*': 'ptr64',
        'char': 'char8',
        'signed char': 'char8',
        'wchar_t': 'char16',
        'int8_t': 'int8',
        'int8': 'int8',
        'int16_t': 'int16',
        'int16': 'int16',
        'short': 'int16',
        'int32_t': 'int32',
        'int32': 'int32',
        'int': 'int32',
        'long': 'int32',
        'int64_t': 'int64',
        'int64': 'int64',
        '__int64': 'int64',
        'long long': 'int64',
        'uint8_t': 'uint8',
        'uint8': 'uint8',
        'unsigned char': 'uint8',
        'byte': 'uint8',
        'uint16_t': 'uint16',
        'uint16': 'uint16',
        'unsigned short': 'uint16',
        'uint32_t': 'uint32',
        'uint32': 'uint32',
        'unsigned int': 'uint32',
        'unsigned long': 'uint32',
        'uint64_t': 'uint64',
        'uint64': 'uint64',
        'unsigned __int64': 'uint64',
        'unsigned long long': 'uint64',
        'bool*': 'bool*',
        'float*': 'float*',
        'double*': 'double*',
        'void**': 'ptr64*',
        'wchar_t*': 'char16*',
        'int8_t*': 'int8*',
        'int8*': 'int8*',
        'int16_t*': 'int16*',
        'int16*': 'int16*',
        'short*': 'int16*',
        'int32_t*': 'int32*',
        'int32*': 'int32*',
        'int*': 'int32*',
        'long*': 'int32*',
        'int64_t*': 'int64*',
        'int64*': 'int64*',
        '__int64*': 'int64*',
        'long long*': 'int64*',
        'uint8_t*': 'uint8*',
        'uint8*': 'uint8*',
        'unsigned char*': 'uint8*',
        'byte*': 'uint8*',
        'uint16_t*': 'uint16*',
        'uint16*': 'uint16*',
        'unsigned short*': 'uint16*',
        'uint32_t*': 'uint32*',
        'uint32*': 'uint32*',
        'unsigned int*': 'uint32*',
        'unsigned long*': 'uint32*',
        'uint64_t*': 'uint64*',
        'uint64*': 'uint64*',
        'unsigned __int64*': 'uint64*',
        'unsigned long long*': 'uint64*',
    }
    return switch_dict.get(type, '?')


def main(folder_dir, output_file):
    if not folder_dir:
        folder_dir = os.getcwd()
    else:
        if not os.path.isdir(folder_dir):
            print(f'Folder with headers not exists {folder_dir}')
            return 1
    exported_methods = []
    search_pattern = os.path.join(folder_dir, f"*.h")
    file_list = glob.glob(search_pattern)
    for file_path in file_list:
        with open(file_path, 'r') as file:
            file_contents = file.read()
            contents = file_contents.replace('extern "C"', '').replace('PLUGIN_API', '')
            parsed = simple.parse_string(contents, options=None)
            for function in parsed.namespace.functions:
                param_types = []
                for param in function.parameters:
                    param_types.append({
                        'type': convert_type(param.type.format()),
                        'name': param.name.format()
                    })
                exported_methods.append({
                    'name': function.name.format(),
                    'funcName': function.name.format(),
                    'paramTypes': param_types,
                    'retType': {
                        'type': convert_type(function.return_type.format())
                    }
                })

    if not output_file:
        print(json.dumps(exported_methods, indent=2))
    else:
        with open(output_file, 'w') as json_file:
            json.dump(exported_methods, json_file, indent=2)


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--folder')
    parser.add_argument('--output')
    return parser.parse_args()


if __name__ == '__main__':
    args = get_args()
    sys.exit(main(args.folder, args.output))
