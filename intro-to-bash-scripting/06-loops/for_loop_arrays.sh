#!/bin/bash

my_array=("A" "few" "strings" "in" "an" "array")

for item in "${my_array[@]}"; do  #Gets array as string seperated by spaces
	echo "${item}"
done
