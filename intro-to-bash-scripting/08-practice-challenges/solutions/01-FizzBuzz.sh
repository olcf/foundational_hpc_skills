#!/bin/bash

for (( num=1; num<100; num++ )); do
	if [[ $(($num % 3)) -eq 0 && $((num % 5)) -eq 0 ]]; then
		echo "FizzBuzz"
	elif [[ $(($num % 3)) -eq 0 ]]; then
		echo "Fizz"
	elif [[ $(($num % 5)) -eq 0 ]]; then                                    echo "Buzz"
	else
		echo "${num}"	
	fi
done
