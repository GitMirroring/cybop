#!/bin/bash

PATH="/home/project/cybop/src/controller:${PATH}"

java -jar CybopBenchmarkViewer.jar \
    --scriptpath=/home/project/cybop/tools/benchmark/start_benchmark.sh \
    --programpath=/home/project/cybop/tools/benchmark \
    --runtimes=$1
