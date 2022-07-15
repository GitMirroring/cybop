#!/usr/bin/python
import os
import re


class ApiItem:
    def __init__(self, name: str, location: str) -> None:
        self.name = name
        self.location = location
        self.elements = []


basePath = os.path.join(os.path.dirname(__file__), '..', '..')
pathToConstant = os.path.join(basePath, 'src', 'constant')
pathToOutput = os.path.join(basePath, 'doc', 'cybol', 'api')


apiItems = [
    ApiItem('channel', os.path.join(pathToConstant, 'channel', 'cybol')),
    ApiItem('logic', os.path.join(pathToConstant, 'format', 'cybol', 'logic')),
    ApiItem('state', os.path.join(pathToConstant, 'format', 'cybol', 'state'))
]

variableMatch = re.compile("^(?:static wchar_t\* )[A-Z_]+(?: = L\")(?P<value>.+)(?:\";)")


def parse_format(filename, api_item):
    with open(filename) as file_content:
        lines = file_content.readlines()
        for line in lines:
            pattern_match = variableMatch.search(line)
            if pattern_match:
                print(pattern_match.group(1))
                api_item.elements.append(pattern_match.group(1))


def persist_information(api_item):
    with open(os.path.join(pathToOutput, api_item.name + '.txt'), 'w') as outfile:
        api_item.elements.sort()
        outfile.write("\n".join(api_item.elements))


for apiItem in apiItems:
    print('processing ' + apiItem.name)
    for path, dirs, files in os.walk(apiItem.location):
        for file in files:
            print('processing file: ' + file)
            parse_format(os.path.join(path, file), apiItem)

    persist_information(apiItem)
