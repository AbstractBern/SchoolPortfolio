#!/usr/bin/env python
# Programmer: Bernardo F
# 11/22/2021
# romanamor.py program does a proof for roman.py and namor.py
# converts to roman and back to digit
import sys
import os
# tuple holding roman numerals and their place values and max counts
ROMAN_TUP = ( ('M', 1000, 3), ('CM', 900, 1), ('D', 500, 1),
            ('CD', 400, 1), ('C', 100, 3),('XC', 90, 1), 
			('L', 50, 1),('XL', 40, 1), ('X', 10, 3),('IX', 9, 1), 
			('V', 5, 1), ('IV', 4, 1), ('I', 1, 3) )

# a list of the place values for roman numerals
ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
thousands = ["", "M", "MM", "MMM"]

# numberConversion converts a digit from 0 to 3999 to roman numeral
def numberConversion(digit):
	# fill place values for each position of the digit to get a numeral
	# we can isolate our place values like this
	if digit >= 4000:
		return "Error"
	thousand = thousands[digit//1000]
	hundred = hundreds[(digit % 1000)//100]
	ten = tens[(digit % 100)//10]
	one = ones[digit % 10]
	# we can get our roman nu
	romanNumeral = (thousand + hundred + ten + one)
	return romanNumeral;
# parseNumeral parses romanNumeral from true value 0-3999 back to digit
def parseNumeral(romanNumeral):
	index = 0
	digit = 0
	# loop through tuple finding char at index
	for numeral, value, maxcount in ROMAN_TUP:
		sameChars = 0
		# traverse through characters in romanNumeral
		while romanNumeral[index: index+len(numeral)] == numeral:
			# count tells us how much of one character we found
			sameChars += 1
			if sameChars > maxcount:
				return 0
			digit += value
			# helps position our index slice
			index += len(numeral)
	if index < len(romanNumeral):
		return 0
	return digit
def main():
	warnings = 0
	# initial 0 warnings and count up to 4000 validations
	for i in range(0,4001):
		roman = numberConversion(i)
		if i == parseNumeral(roman):
			pass
		else:
			warnings = warnings + 1
	print("Converted {} to Error back to 0, which is wrong.".format(i))
	print("Checked values from 0 to 4000. Errors = {}".format(warnings))
main()
