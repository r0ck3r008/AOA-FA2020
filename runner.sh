#!/bin/bash

# Generate 4 input files
i=1
while [ $i -le 4 ];
do
        val=$((10 ** $i))
        python ./tc_generate.py "$val" testcases/tc"$val".txt
        i=$(( $i + 1 ))
done
