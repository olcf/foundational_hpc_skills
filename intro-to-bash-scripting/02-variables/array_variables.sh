#!/bin/bash

fruits=("apple" "cherry" "grapefruit" "orange")
echo "${fruits[1]}"
echo "${fruits[@]:0:2}"
echo "${fruits[*]}"
printf "\n"
desserts=("cookies" "cake" "brownies")
echo "${desserts[*]}"
desserts[3]="ice_cream"
echo "${desserts[*]}"
unset desserts[0]
declare -p desserts
echo "${desserts[*]}"
desserts[0]="popsicles"
echo "${desserts[*]}"




