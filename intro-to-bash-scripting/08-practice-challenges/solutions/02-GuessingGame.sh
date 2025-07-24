#!/bin/bash

num=$(( 1 + $RANDOM % 10 ))  #This is just pseudo-random since it it based on seeding, but whatever..
			     #True randomness dosen't really exist in computing anyway

read -p "Enter a number between 1 and 10, or enter 'q' to quit: " guess
if [[ "$guess" =~ [qQ] ]]; then
	echo "Game aborted. Exiting.."
	exit 0
elif [[ ! "$guess" =~ ^[0-9]+$  ]]; then
        echo "That isn't a number!!!"
	guess="invalid"
fi

while [[ $num -ne $guess ]]; do
	if [[ $guess -lt $num && $guess -ne "invalid" ]]; then
		echo "${guess} is too low"
	elif [[ $guess -gt $num && $guess -ne "invalid" ]]; then
		echo "${guess} is too high"
	fi

	read -p "Enter a number between 1 and 10, or enter 'q' to quit: " guess
	if [[ "$guess" =~ [qQ] ]]; then
        	echo "Game aborted. Exiting.."
        	exit 0
	elif [[ ! "$guess" =~ ^[0-9]+$  ]]; then
        	echo "That isn't a number!!!"
        	guess="invalid"
	fi
done

echo "You got it! $guess is the correct number."

