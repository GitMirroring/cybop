#!/usr/bin/python

import itertools
import os
import sys
''' should convert the following block
/** The kbv test number field xdt cyboi name. */
#static wchar_t KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_ARRAY[] = {L'k', L'b', L'v', L'_', L't', L'e', L's', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
#static wchar_t* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME = KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_ARRAY;
#static int* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

into

/** The kbv test number field xdt cyboi name. */
static wchar_t* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME = L"kbv_test_number";
static int* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

should also work if the javadoc is span over several lines like

/** 
* The kbv test number field xdt cyboi name. 
*
* This is another javdoc entry
*/
#static wchar_t KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_ARRAY[] = {L'k', L'b', L'v', L'_', L't', L'e', L's', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
#static wchar_t* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME = KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_ARRAY;
#static int* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;


'''

if (len(sys.argv) != 2):
    raise Exception("needs a relativ path to the file")

relativPath = sys.argv[1]
sourceFile = relativPath
destinationFile = sourceFile + "_copy"

def group_separator(line):
    return line=='\n'

def createNewDefinition(lines, indexLastElement):
    rareName = lines[indexLastElement - 2]
    leftIndexName = rareName.find('{') + 1
    rightIndexName = rareName.find('}') - 1
    name = rareName[leftIndexName:rightIndexName].replace('\'', '').replace(' ', '').replace(',', '').replace('L', '')
    rareDefinition = lines[indexLastElement - 1]
    rightIndexDef = rareDefinition.find(' =')
    definition = rareDefinition[0:rightIndexDef]
    return definition + ' = L"' + name + '";\n'

f = open(sourceFile,"r")
f2 = open(destinationFile,"w")
for key,group in itertools.groupby(f,group_separator):
    lines = list(group)
    if (lines[0].startswith("/**")):
        if (sum(line.startswith('static') for line in lines) != 3):
            raise Exception("there need to be a block of 3 static definitions")

        for line in lines:
            if not line.startswith('static'):
                f2.write(line)

        indexLastElement = len(lines) - 1
        f2.write(createNewDefinition(lines, indexLastElement))
        f2.write(lines[indexLastElement])
    else:
        for line in lines:
            f2.write(line)

f.close()
f2.close()

os.remove(sourceFile)
os.rename(destinationFile, sourceFile)