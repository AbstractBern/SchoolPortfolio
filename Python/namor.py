# Programmer: Bernardo Flores
# 11/22/2021
# namor.py program converts roman numerals to their digit values

import sys
import os
# tuple holding roman numerals and their place values and max counts
# parseNumeral parses romanNumeral and returns its true value
# This order of numerals, we can successfully get the numbers to translate
ROMAN_TUP = ( ('M', 1000, 3), ('CM', 900, 1), ('D', 500, 1),
            ('CD', 400, 1), ('C', 100, 3),('XC', 90, 1), 
			('L', 50, 1),('XL', 40, 1), ('X', 10, 3),('IX', 9, 1), 
			('V', 5, 1), ('IV', 4, 1), ('I', 1, 3) )
def parseNumeral(romanNumeral):
	index = 0
	digit = 0
	# loop through tuple finding char at index
	for numeral, value, total in ROMAN_TUP:
		sameChars = 0
		# traverse through characters in romanNumeral
		while romanNumeral[index: index+len(numeral)] == numeral:
			# count tells us how much of one character we found
			sameChars += 1
			if total < sameChars:
				return 0
			index += len(numeral)
			digit += value
	if index < len(romanNumeral):
		return 0
	return digit

def main():
    # case for one or more outputs
    if len(sys.argv) == 2:
        numeral = sys.argv[1].upper()
        number = parseNumeral(numeral)
        print("{} is {}".format(numeral,number))
    elif len(sys.argv) > 2:
        for i in range(1, len(sys.argv), 1):
            numeral = sys.argv[i].upper()
            number = parseNumeral(numeral)
            print("{} is {}".format(numeral,number))
    else:
        print("ERROR: not enough arguments!")
main()
