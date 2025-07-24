#!/bin/bash

items=()  #Initalizes an empty array
read -p "Enter a string, or type 'exit' to quit: " entry

while [[ "${entry}" != "exit" ]]; do
	items+=("$entry")
	read -p "Enter a string, or type 'exit' to quit: " entry
done

echo "Items you have entered: "
for i in ${items[@]}; do
	echo $i
done

