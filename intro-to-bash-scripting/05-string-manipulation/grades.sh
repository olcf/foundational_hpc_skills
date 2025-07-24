#!/bin/bash

read -p "Enter a score (0-100): " score

case $score in
	[9][0-9]|100) #) Marks the beginning of a case-output. This is what you do once case [9][0-9]|100 is reached.
		echo "Grade: A"
		;;  #Notice the double ;; marking the end of a case-output
	[8][0-9])  
        	echo "Grade: B"
        	;;
    	[7][0-9])
        	echo "Grade: C"
        	;;  #As with all things in bash, indentation not neccesary but reccomended.
    	[6][0-9])
        	echo "Grade: D"
        	;;
    	[0-5][0-9])
        	echo "Grade: F"
        	;;
    	*)
        	echo "Invalid score."
        	;;
esac
