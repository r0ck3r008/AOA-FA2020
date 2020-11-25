#!/bin/bash

# Generate 4 input files
i=1
if [ -n "$1" ];
then
        while [ $i -le 4 ];
        do
                val=$((10 ** $i))
                python ./tc_generate.py "$val" testcases/tc"$val".txt
                i=$(( $i + 1 ))
        done
fi

i=1
while [ $i -le 4 ];
do
        val=$((10 ** $i))
        ./AlgoTowers testcases/tc"$val".txt | awk -v="$val" 'print{val,$0}' >> tmp/data.csv
        i=$(( $i + 1 ))
done

sort -t, -k1 tmp/data.csv
