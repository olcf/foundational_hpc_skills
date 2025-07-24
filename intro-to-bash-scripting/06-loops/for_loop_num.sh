#!bin/bash

read -p "Enter a number: " num 

for (( i=0; i<=num; i++)); do  #C-style syntax for loops
	echo $i
done
