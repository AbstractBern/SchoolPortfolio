#!/usr/bin/env python
# Programmer: Bernardo Flores
# 11/21/2021
# roman.py converts a number to a roman numeral and accepts any amount of parameters to sys.argv
import os
import sys
# 4 lists of the place values for roman numerals
ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
thousands = ["", "M", "MM", "MMM"]

# numberConversion converts a digit from 0 to 3999 to roman numeral
def numberConversion(digit):
	# fill iplace values for each position of the digit to get a numeral
	# we can isolate our place values like this
	thousand = thousands[digit//1000]
	hundred = hundreds[(digit%1000)//100]
	ten = tens[(digit%100)//10]
	one = ones[digit%10]
	# we can get our roman numeral like this
	romanNumeral = thousand + hundred + ten + one
	return romanNumeral

def main():
	if len(sys.argv) == 2:
		number = int(sys.argv[1])
		if number <= 0 or number > 3999:
			print("{} is error!".format(number))
		else:
			romanNumeral = numberConversion(number)
			print("{} is {}".format(number,romanNumeral))
	elif len(sys.argv) > 2:
		for i in range(1, len(sys.argv), 1):
			number = int(sys.argv[i])
			if number <= 0 or number > 3999 or not (sys.argv[i]).isdigit():
				print("{} is error!".format(number))
			else:
				# simplicity, assume the var is a string for parse
				romanNumeral = numberConversion(number)
				print("{} is {}".format(number,romanNumeral))
	else:
		print("ERROR: not enough arguments!")
main()
