#!/bin/bash


add_two_numbers () {
	local sum
	sum=$(($num1 + $num2))
	echo "${num1}+${num2}=${sum}"

}

main () {
	local num1
	local num2

	read -p "Enter an integer: " num1
	read -p "Enter an integer: " num2
	add_two_numbers num1 num2
}

main

