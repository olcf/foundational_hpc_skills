#!/bin/bash


var_predefined="Predefined global variable"

my_vars () {
	var_global="Global Variable"
	local var1
	var_local="Local Variable"
}

echo "${var_predefined}"  #A regular function defined outside of the function scopre
echo "${var_global}"  #Since my_vars has not been called yet, var_global has not been set. echoes NULL

my_vars  #Function call to intialize my set variables"

echo "${var_global}"  #Since my_vars has been called, this global variable is visible.
echo "${var_local}"  #This is a local variable. Thus, the variable is unfindable here. echoes NULL

