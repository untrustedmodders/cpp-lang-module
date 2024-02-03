#!/usr/bin/python3
import sys
import argparse
import os
import json
from enum import Enum


TYPES_MAP = {
    'void': 'void',
    'int32': 'int',
    'float': 'float',
    'double': 'double',
    'string': 'const std::string&',
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


def convert_type(type_name):
    return TYPES_MAP.get(type_name, 'int')


class ParamGen(Enum):
    Types = 1
    Names = 2
    TypesNames = 3


def gen_params_string(params, param_gen: ParamGen):
    def gen_param(param):
        if param_gen == ParamGen.Types:
            return convert_type(param['type'])
        if param_gen == ParamGen.Names:
            return param['name']
        return f'{convert_type(param["type"])} {param["name"]}'

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
        return_type = convert_type(method["retType"]["type"])
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
