#!/bin/bash

read -p "Enter a number: " my_num

if [[ $my_num -gt 10 ]]; then
	echo "Your number is greater than 10."
else
	echo "Your number is NOT greater than 10."
fi

