#!/bin/bash

CYCLES=10
CURRENT=0
QUICK=0
BUBBLE=0
OUTPUT=''

echo "Testing 'sort/quick'."
while [ $CURRENT -lt $CYCLES ]
    do
    OUTPUT=`../../src/controller/cyboi benchmarkQuicksort.cybol`
    OUTPUT=(${OUTPUT[@]})
    OUTPUT="${OUTPUT[0]#0}"
    QUICK=$((QUICK + OUTPUT))
    if ! ((CURRENT % 1))
        then
        echo "$CURRENT% done."
    fi
    ((CURRENT++))
done
((QUICK/=$CYCLES))

((CURRENT=0))
echo "Testing 'sort/bubble'."
while [ $CURRENT -lt $CYCLES ]
    do
    OUTPUT=`../../src/controller/cyboi benchmarkBubblesort.cybol`
    OUTPUT=(${OUTPUT[@]})
    OUTPUT="${OUTPUT[0]#0}"
    BUBBLE=$((BUBBLE + OUTPUT))
    if ! ((CURRENT % 1))
        then
        echo "$CURRENT% done."
    fi
    ((CURRENT++))
done
((BUBBLE/=$CYCLES))

echo "Mean duration of 'sort/quick' is $QUICK ms."
echo "Mean duration of 'sort/bubble' is $BUBBLE ms."
