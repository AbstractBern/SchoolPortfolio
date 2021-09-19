# Bernard FLores
# COSC1336, Lab 9
# 12/6/16
# make sets and perfrom operations, some strings as well.
    #set of alphabets; Not sure if wanted alphabetize, if so HOW?
alpha = set()
print("======================")
print("Set of Alphabets:")
for letter in range(ord('a'), ord('z')+1):
	alpha.add(chr(letter))
print(alpha)
    #consonants in alpha
print("=====================")
print("Without vowels:")
vowels = set('aeiouy')
new_alpha = alpha-vowels
print(new_alpha)
    #set of vowels
print('=====================')
print('Set of vowels:')
vowel_mod = alpha-new_alpha
print(vowel_mod)
    #set of digits 0 through 9
print("======================")
print("Set of digits::")
digit = set()
for num in range(0, 10):
    digit.add(num)
print(digit)
    #set of even numbers, No end given; so I said 10.
print("======================")
print("Set of even numbers:")
even = set()
count = -2
for num in range(10):
    count += 2
    even.add(count)
print(even)
    #odd number set
print("=====================")
print("Odd Numbers:")
oddNum = set()
count = -1
for num in range(10):
    count+=2
    oddNum.add(count)
print(oddNum)
    #set of punctuations
print("======================")
print("Set of punctuation:")
punct = set()
punctuation = "~`!@#$%^&*()_-+={[}]|\:;”’<,>.?/"
punct.add(punctuation)
print(punct)
    #matching punctuation char;
print("======================")
print("Set of punctuation pairs:")
match = set()
punct = '<>','[]','{}','()'
match.add(punct)
print(match)
    #advice string
print("======================")
print("Set of advice:")
advice = set()
targ = ["treat others kindly"]
advice.update(targ)
print(advice)
    #set of vowels not in advice
print("======================")
print('Vowels not in advice:')
pun2 = set(' ')
word = set('treat others kindly')
vowels = set('aeiouy')
new_string1 = word-pun2
consonants = new_string1-vowels
new_string2 = word-pun2
vowels_notin = new_string2-consonants
vow_not= vowels.difference(vowels_notin)
print(vow_not)
    #advice_consonant
print('======================')
print('Consonants in advice:')
pun1 = set(' ')
vowels = set('aeiouy')
word = set('treat others kindly')
new_string = word-pun1
consonants = new_string-vowels
print(consonants)
    #address string
print("======================")
print("Set of address:")
address = set()
string3= ["11928 stonehollow dr., austin, tx (us [of] a)"]
address.update(string3)
print(address)
    #odd_address
print("======================")
print("Set of odd num in address:")
odd_address = set()
string4 = set("11928 stonehollow dr., austin, tx (us [of] a)")
new_string = string4-alpha
punctuation1 = set('{}[],./<>?;:/*-+!@#$%^&*()+-_= ')
newer_string = new_string-punctuation1
print(newer_string)
    #punctuation in address
print("======================")
punct_address = set()
print("Set of punctuation in address:")
digit_New = set('0123456789')
string4 = set('11928 stonehollow dr., austin, tx (us [of] a)')
stringMod = string4-alpha
stringMod2 = stringMod-digit_New
print(stringMod2)
    #punctuation in address not in match pairs
print("======================")
print('Punctuation not in address:')
address1 = set('11928 stonehollow dr., austin, tx (us [of] a)')
punct_now = set('<>[]{}()')
differ_address = punct_now.difference(stringMod2)
print(differ_address)
#program output
##======================
##Set of Alphabets:
##{'h', 'o', 'j', 'v', 'i', 'a', 'r', 'l', 'f', 'w', 'q', 's', 'n', 'd', 'u', 'g', 'b', 'e', 'm', 'p', 'k', 't', 'y', 'c', 'x', 'z'}
##=====================
##Without vowels:
##{'s', 't', 'n', 'd', 'h', 'c', 'r', 'j', 'v', 'g', 'l', 'f', 'b', 'm', 'w', 'x', 'z', 'p', 'q', 'k'}
##=====================
##Set of vowels:
##{'a', 'u', 'o', 'y', 'e', 'i'}
##======================
##Set of digits::
##{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
##======================
##Set of even numbers:
##{0, 2, 4, 6, 8, 10, 12, 14, 16, 18}
##=====================
##Odd Numbers:
##{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}
##======================
##Set of punctuation:
##{'~`!@#$%^&*()_-+={[}]|\\:;”’<,>.?/'}
##======================
##Set of punctuation pairs:
##{('<>', '[]', '{}', '()')}
##======================
##Set of advice:
##{'treat others kindly'}
##======================
##Vowels not in advice:
##{'u'}
##======================
##Consonants in advice:
##{'s', 't', 'n', 'd', 'h', 'r', 'l', 'k'}
##======================
##Set of address:
##{'11928 stonehollow dr., austin, tx (us [of] a)'}
##======================
##Set of odd num in address:
##{'1', '2', '8', '9'}
##======================
##Set of punctuation in address:
##{' ', ')', '(', '[', ',', ']', '.'}
##======================
##Punctuation not in address:
##{'<', '>', '}', '{'}
