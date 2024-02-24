#!/usr/bin/python3
import sys
import argparse
import os
import json
from enum import Enum


VAL_TYPES_MAP = {
    'void': 'void',
    'bool': 'bool',
    'char8': 'char',
    'char16': 'char16_t',
    'int8': 'int8_t',
    'int16': 'int16_t',
    'int32': 'int32_t',
    'int64': 'int64_t',
    'uint8': 'uint8_t',
    'uint16': 'uint16_t',
    'uint32': 'uint32_t',
    'uint64': 'uint64_t',
    'ptr64': 'void*',
    'float': 'float',
    'double': 'double',
    'function': 'delegate',
    'string': 'const std::string&',
    'bool*': 'const std::vector<bool>&',
    'char8*': 'const std::vector<char>&',
    'char16*': 'const std::vector<char16_t>&',
    'int8*': 'const std::vector<int8_t>&',
    'int16*': 'const std::vector<int16>&',
    'int32*': 'const std::vector<int32>&',
    'int64*': 'const std::vector<int64>&',
    'uint8*': 'const std::vector<uint8>&',
    'uint16*': 'const std::vector<uint16>&',
    'uint32*': 'const std::vector<uint32>&',
    'uint64*': 'const std::vector<uint64>&',
    'ptr64*': 'const std::vector<void*>&',
    'float*': 'const std::vector<float>&',
    'double*': 'const std::vector<double>&',
    'string*': 'const std::vector<std::string>&'
}


REF_TYPES_MAP = {
    'void': 'void',
    'bool': 'bool&',
    'char8': 'char&',
    'char16': 'char16_t&',
    'int8': 'int8_t&',
    'int16': 'int16_t&',
    'int32': 'int32_t&',
    'int64': 'int64_t&',
    'uint8': 'uint8_t&',
    'uint16': 'uint16_t&',
    'uint32': 'uint32_t&',
    'uint64': 'uint64_t&',
    'ptr64': 'void*&',
    'float': 'float&',
    'double': 'double&',
    'function': 'delegate',
    'string': 'std::string&',
    'bool*': 'std::vector<bool>&',
    'char8*': 'std::vector<char>&',
    'char16*': 'std::vector<char16_t>&',
    'int8*': 'std::vector<int8_t>&',
    'int16*': 'std::vector<int16>&',
    'int32*': 'std::vector<int32>&',
    'int64*': 'std::vector<int64>&',
    'uint8*': 'std::vector<uint8>&',
    'uint16*': 'std::vector<uint16>&',
    'uint32*': 'std::vector<uint32>&',
    'uint64*': 'std::vector<uint64>&',
    'ptr64*': 'std::vector<void*>&',
    'float*': 'std::vector<float>&',
    'double*': 'std::vector<double>&',
    'string*': 'std::vector<std::string>&'
}


def validate_manifest(wplugin):
    parse_errors = []
    methods = wplugin.get('exportedMethods')
    if type(methods) is list:
        for i, method in enumerate(methods):
            if type(method) is dict:
                if type(method.get('type')) is str:
                    parse_errors += [f'root.exportedMethods[{i}].type not string']
            else:
                parse_errors += [f'root.exportedMethods[{i}] not object']
    else:
        parse_errors += ['root.exportedMethods not array']
    return parse_errors


def convert_type(type_name, is_ref: False):
    if is_ref:
        return REF_TYPES_MAP.get(type_name, 'int')
    else:
        return VAL_TYPES_MAP.get(type_name, 'int')


class ParamGen(Enum):
    Types = 1
    Names = 2
    TypesNames = 3


def gen_params_string(params, param_gen: ParamGen):
    def gen_param(param):
        if param_gen == ParamGen.Types:
            return convert_type(param['type'], 'is_ref' in param)
        if param_gen == ParamGen.Names:
            return param['name']
        return f'{convert_type(param["type"], "is_ref" in param)} {param["name"]}'

    output_string = ''
    if params:
        it = iter(params)
        output_string += gen_param(next(it))
        for p in it:
            output_string += f', {gen_param(p)}'
    return output_string


def main(manifest_path, output_dir):
    if not os.path.isfile(manifest_path):
        print(f'Manifest file not exists {manifest_path}')
        return 1
    if not os.path.isdir(output_dir):
        print(f'Output folder not exists {output_dir}')
        return 1

    plugin_name = os.path.splitext(os.path.basename(manifest_path))[0]
    header_file = os.path.join(output_dir, 'wps', f'{plugin_name}.h')
    if os.path.isfile(header_file):
        print(f'Already exists {header_file}')
        return 1

    with open(manifest_path, 'r', encoding='utf-8') as fd:
        wplugin = json.load(fd)

    parse_errors = validate_manifest(wplugin)
    if parse_errors:
        print('Parse fail:')
        for error in parse_errors:
            print(f'  {error}')
        return 1

    content = ''

    content += '#pragma once\n'
    content += '\n'
    content += '#include <plugify/cpp_plugin.h>\n'
    content += '\n'
    content += f'namespace {plugin_name} {{\n'
    for method in wplugin['exportedMethods']:
        return_type = convert_type(method["retType"]["type"], "ref" in method["retType"])
        content += (f'\tinline {return_type} '
                    f'{method["name"]}({gen_params_string(method["paramTypes"], ParamGen.TypesNames)}) {{\n')
        content += (f'\t\tusing {method["name"]}Fn = {return_type} '
                    f'(*)({gen_params_string(method["paramTypes"], ParamGen.Types)});\n')
        content += (f'\t\tstatic auto func = '
                    f'reinterpret_cast<{method["name"]}Fn>(plugify::GetMethod("{plugin_name}.{method["name"]}"));\n')
        content += (f'\t\t{"return " if method["retType"]["type"] != "void" else ""}'
                    f'func({gen_params_string(method["paramTypes"], ParamGen.Names)});\n')
        content += '\t}\n'
    content += '}\n'

    with open(header_file, 'w', encoding='utf-8') as fd:
        fd.write(content)

    return 0


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('manifest')
    parser.add_argument('output')
    return parser.parse_args()


if __name__ == '__main__':
    args = get_args()
    sys.exit(main(args.manifest, args.output))
