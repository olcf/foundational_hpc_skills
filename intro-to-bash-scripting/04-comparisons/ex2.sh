#!/bin/bash

read -p "Enter a number: " n 

if [[ $n -lt 3 ]]; then
	echo "My number is less than 3"
elif [[ $n -eq 4 ]]; then
	echo "My number is 4"
elif [[ $n -eq 5 ]]; then
	echo "My number is 5"
elif [[ $n -ge 6 ]]; then
	echo "My number is 6 or greater"
else
	echo "My number is 3."
fi



