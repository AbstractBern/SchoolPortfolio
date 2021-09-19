Python 3.5.2 (v3.5.2:4def2a2901a5, Jun 25 2016, 22:18:55) [MSC v.1900 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> attempt = "BabySitter"
>>> for char in attempt:
	print(attempt[0], attempt[3], attempt[8])

	
B y e
B y e
B y e
B y e
B y e
B y e
B y e
B y e
B y e
B y e
>>> for char in range(1):
	print(attempt[0], attempt[3], attempt[8])

	
B y e
>>> len(attempt)
10
>>> attempt+="at home"
>>> attempt
'BabySitterat home'
>>> attempt+=" at home"
>>> attempt
'BabySitterat home at home'
>>> attempt-" at home"
Traceback (most recent call last):
  File "<pyshell#11>", line 1, in <module>
    attempt-" at home"
TypeError: unsupported operand type(s) for -: 'str' and 'str'
>>> 
>>> attempt
'BabySitterat home at home'
>>> for "at home" in attempt
SyntaxError: invalid syntax
>>> defor "at home" in attempt:
	
SyntaxError: invalid syntax
>>> for "at home" in attempt:
	del
	
SyntaxError: invalid syntax
>>> attempt[10:-1]
'at home at hom'
>>> attempt
'BabySitterat home at home'
>>> attempt.rstrip("at home")
'BabySitter'
>>> attempt
'BabySitterat home at home'
>>> attempt = attempt.rstrip("at home")
>>> 
>>> attempt
'BabySitter'
>>> attempt+" at home."
'BabySitter at home.'
>>> attempt
'BabySitter'
>>> attempt = attempt+" at home."
>>> attempt
'BabySitter at home.'
>>> print("What do I do?")
What do I do?
>>> print(attempt.rstrip("Sit"), attempt[11:17])
BabySitter at home. at hom
>>> print("What do I do?")
What do I do?
>>> print(attempt.rstrip("Sit"), attempt[11:17])
BabySitter at home. at hom
>>> print(attempt.rstrip("Sit"), attempt[11:18])
BabySitter at home. at home
>>> print(attempt[4:6], attempt[11:18])
Si at home
>>> print("What do I do?")
What do I do?
>>> print(attempt[4:7], attempt[11:18])
Sit at home
>>> 
>>> attempt = print(attempt[4:7], attempt[11:18])
Sit at home
>>> attempt
>>> attempt
>>> attempt = print(attempt[4:7], attempt[11:18])
Traceback (most recent call last):
  File "<pyshell#41>", line 1, in <module>
    attempt = print(attempt[4:7], attempt[11:18])
TypeError: 'NoneType' object is not subscriptable
>>> attempt = attempt[4:7], attempt[11:18])
SyntaxError: invalid syntax
>>> attempt = attempt[4:7], attempt[11:18]
Traceback (most recent call last):
  File "<pyshell#43>", line 1, in <module>
    attempt = attempt[4:7], attempt[11:18]
TypeError: 'NoneType' object is not subscriptable
>>> list = attempt
>>> list
>>> attempt = 'Sit at home'
>>> isalpha(attempt)
Traceback (most recent call last):
  File "<pyshell#47>", line 1, in <module>
    isalpha(attempt)
NameError: name 'isalpha' is not defined
>>> attempt.isalpha()
False
>>> if "at home" in attempt:
	print("This is my current location.")

	
This is my current location.
>>> string1 = 'Th1rt3en'
>>> if string1.isalnum():
	print(string1, contains alphabetic letters/digits)
	
SyntaxError: invalid syntax
>>> if string1.isalnum():
	print(string1, "contains alphabetic letters/digits")

	
Th1rt3en contains alphabetic letters/digits
>>> else:
	
SyntaxError: invalid syntax
>>> else:
	
SyntaxError: invalid syntax
>>> else:
	
SyntaxError: invalid syntax
>>> if string1.isalpha():
	print(string1, "meets the description")

	
>>> if string1.isalpha():
	print(string1, "true", "only alphabetic letters")
else:
	print(string1, "False", "contains both letters and numbers ")

	
Th1rt3en False contains both letters and numbers 
>>> if string1.isdigit():
	print(string1, "only numbers, True")
else:
	print(string1, "does not contain only numbers")

	
Th1rt3en does not contain only numbers
>>> if string1.islower():
	print("all letters are lowercase")
else:
	print(False)

	
False
>>> if string1.isspace():
	print("contains only whitespace char.")
else:
	print("otherwise")

	
otherwise
>>> if string1.isupper():
	print(string1, "All letters are uppercase and one alphabet letter")
else:
	print(string1, "Otherwiise")

	
Th1rt3en Otherwiise
>>> Kings = 'YOU GOTTA BELIEVE'
>>> if kings.isupper():
	print(True, kings)Kings = 'YOU GOTTA BELIEVE'
	
SyntaxError: invalid syntax
>>> kings = 'YOU GOTTA BELIEVE'
>>> if kings.isupper():
	print(True, kings)
else:
	print(False)

	
True YOU GOTTA BELIEVE
>>> kings.lower()
'you gotta believe'
>>> kings.lstrip()
'YOU GOTTA BELIEVE'
>>> stutter = 'w w w what'
>>> stutter.lstrip()
'w w w what'
>>> stutter = '"\n"w w w what'
>>> stutter
'"\n"w w w what'
>>> stutter = '\nw w w what'
>>> stutter
'\nw w w what'
>>> stutter = 'what\nNow'
>>> stutter
'what\nNow'
>>> stutter = 'what"\n"Now'
>>> stutter
'what"\n"Now'
>>> stutter = 'what now\ndo'
>>> stutter
'what now\ndo'
>>> del stutter
>>> bars = "pistol"\t"grip"\t"pump"
SyntaxError: unexpected character after line continuation character
>>> bars = ("pistol"\t"grip"\t"pump")
SyntaxError: unexpected character after line continuation character
>>> bars = ("pistol"\t"grip"\t"pump");
SyntaxError: unexpected character after line continuation character
>>> bars = ("pistol"\t"grip"\t"pump"\n)
SyntaxError: unexpected character after line continuation character
>>> bars
Traceback (most recent call last):
  File "<pyshell#117>", line 1, in <module>
    bars
NameError: name 'bars' is not defined
>>> print(string1, "meets the description")
Th1rt3en meets the description
>>> ("pistol"\t"grip"\t"pump"\n)
SyntaxError: unexpected character after line continuation character
>>> print("pistol"\t"grip"\t"pump")
SyntaxError: unexpected character after line continuation character
>>> print("pistol\tgrip\tpump")
pistol	grip	pump
>>> bars = "pistol\tgrip\tpump"
>>> brs
Traceback (most recent call last):
  File "<pyshell#123>", line 1, in <module>
    brs
NameError: name 'brs' is not defined
>>> bars
'pistol\tgrip\tpump'
>>> bars = print("pistol\tgrip\tpump")
pistol	grip	pump
>>> bars
>>> bars = 'pistol grip pump'
>>> bars.lstrip()
'pistol grip pump'
>>> bars.strip('pump')
'istol grip '
>>> bars.strip('i,s,t,o,l,g')
'pistol grip pump'
>>> bars.strip('p')
'istol grip pum'
>>> bars.strip('p', 'g', 'p'))
SyntaxError: invalid syntax
>>> bars.strip('p', 'g', 'p')
Traceback (most recent call last):
  File "<pyshell#133>", line 1, in <module>
    bars.strip('p', 'g', 'p')
TypeError: strip() takes at most 1 argument (3 given)
>>> space = '    Nuclear    Assault    '
>>> space.lstrip()
'Nuclear    Assault    '
>>> space.rstrip()
'    Nuclear    Assault'
>>> band = space.strip()
>>> band
'Nuclear    Assault'
>>> band = band[0:7], band[11:17]
>>> band
('Nuclear', 'Assaul')
>>> band = band[0:6], band[11:17]
>>> band
(('Nuclear', 'Assaul'), ())
>>> del band
>>> for char in space:
	del '    '
	
SyntaxError: can't delete literal
>>> band.strip('    ')
Traceback (most recent call last):
  File "<pyshell#147>", line 1, in <module>
    band.strip('    ')
NameError: name 'band' is not defined
>>> space.strip('    ')
'Nuclear    Assault'
>>> band = space.strip('    ')
>>> bad
Traceback (most recent call last):
  File "<pyshell#150>", line 1, in <module>
    bad
NameError: name 'bad' is not defined
>>> band
'Nuclear    Assault'
>>> band.strip('    ')
'Nuclear    Assault'
>>> band.del('   ')
SyntaxError: invalid syntax
>>> #ofcourse
>>> len(band)
18
>>> old_band = band[0:6],' ',band[11:17]
>>> old_band
('Nuclea', ' ', 'Assaul')
>>> old_band = band[0:7],band[11:18]
>>> old_band
('Nuclear', 'Assault')
>>> new_band = old_band.join()
Traceback (most recent call last):
  File "<pyshell#161>", line 1, in <module>
    new_band = old_band.join()
AttributeError: 'tuple' object has no attribute 'join'
>>> new_band = ' '.join(old_band)
>>> new_band
'Nuclear Assault'
>>> print(new_band)
Nuclear Assault
>>> new_band.u
Traceback (most recent call last):
  File "<pyshell#165>", line 1, in <module>
    new_band.u
AttributeError: 'str' object has no attribute 'u'
>>> new_band.upper()
'NUCLEAR ASSAULT'
>>>  new_band.endswith()
 
SyntaxError: unexpected indent
>>> new_band.endswith()
Traceback (most recent call last):
  File "<pyshell#168>", line 1, in <module>
    new_band.endswith()
TypeError: endswith() takes at least 1 argument (0 given)
>>> new_band.endswith('t')
True
>>> string2 = 'Hangar 18'
>>> string2.endswith('Hangar')
False
>>> string2.endswith('18')
True
>>> list1 = []
>>> letters = 'sdlfkjwhag'
>>> for char in letters:
	list1 = letters.find('w')

	
>>> list1
6
>>> state = 'Texas'
>>> state.find('as')
3
>>> state.find('e')
1
>>> ord(statae.find('e'))
Traceback (most recent call last):
  File "<pyshell#184>", line 1, in <module>
    ord(statae.find('e'))
NameError: name 'statae' is not defined
>>> ord(state.find('e'))
Traceback (most recent call last):
  File "<pyshell#185>", line 1, in <module>
    ord(state.find('e'))
TypeError: ord() expected string of length 1, but int found
>>> char(state.find('e'))
Traceback (most recent call last):
  File "<pyshell#186>", line 1, in <module>
    char(state.find('e'))
TypeError: 'str' object is not callable
>>> ch(state.find('e'))
Traceback (most recent call last):
  File "<pyshell#187>", line 1, in <module>
    ch(state.find('e'))
NameError: name 'ch' is not defined
>>> state
'Texas'
>>> position = state.find('ex')
>>> if position != -1:
	print("The wird 'ex' was found at index", position)
else:
	print("'ex' was not found")

	
The wird 'ex' was found at index 1
>>> old_band
('Nuclear', 'Assault')
>>> new_band
'Nuclear Assault'
>>> old_band = new_band.replace('Nuclear', 'Rage Against')
>>> old_band
'Rage Against Assault'
>>> old_band = old_band.replace('Assault', 'The Machine')
>>> print(old_band)
Rage Against The Machine
>>> number = o
Traceback (most recent call last):
  File "<pyshell#201>", line 1, in <module>
    number = o
NameError: name 'o' is not defined
>>> number = 0
>>> for count in range(1,10):
	number+=1
	print(number *count)

	
1
4
9
16
25
36
49
64
81
>>> for count in range(1,10):
	number+=1
	print(number *count)
for count in range(8, 0, -10):
	
SyntaxError: invalid syntax
>>> for count in range(1,10):
	number+=1
	print(number *count)
for count in range(8, 0, -1):
	
SyntaxError: invalid syntax
>>> for count in range(1,10):
	number+=1
	print(number *count)
	for count in range(8, 0, -1):
		print(number *count)

		
10
80
70
60
50
40
30
20
10
22
88
77
66
55
44
33
22
11
36
96
84
72
60
48
36
24
12
52
104
91
78
65
52
39
26
13
70
112
98
84
70
56
42
28
14
90
120
105
90
75
60
45
30
15
112
128
112
96
80
64
48
32
16
136
136
119
102
85
68
51
34
17
162
144
126
108
90
72
54
36
18
>>> #scratch that
>>> string3 = '#'
>>> string3*5
'#####'
>>> for count in range(1,10):
	print(string3*count)
	for count in range(8,0,-1)
	
SyntaxError: invalid syntax
>>> for count in range(1,10):
	print(string3*count)
	for count in range(8,0,-1):
		print(strin3*count)

		
#
Traceback (most recent call last):
  File "<pyshell#222>", line 4, in <module>
    print(strin3*count)
NameError: name 'strin3' is not defined
>>> for count in range(1,10):
	print(string3*count)
	for count in range(8,0,-1):
		print(string3*count)

		
#
########
#######
######
#####
####
###
##
#
##
########
#######
######
#####
####
###
##
#
###
########
#######
######
#####
####
###
##
#
####
########
#######
######
#####
####
###
##
#
#####
########
#######
######
#####
####
###
##
#
######
########
#######
######
#####
####
###
##
#
#######
########
#######
######
#####
####
###
##
#
########
########
#######
######
#####
####
###
##
#
#########
########
#######
######
#####
####
###
##
#
>>> for count in range(1,10):
	print(string3*count)
	for count in range(8,0,-2):
		print(string3*count)

		
#
########
######
####
##
##
########
######
####
##
###
########
######
####
##
####
########
######
####
##
#####
########
######
####
##
######
########
######
####
##
#######
########
######
####
##
########
########
######
####
##
#########
########
######
####
##
>>> for count in range(1,10):
	print(string3*count)
	for count in range(10,0,-1):
		print(string3*count)

		
#
##########
#########
########
#######
######
#####
####
###
##
#
##
##########
#########
########
#######
######
#####
####
###
##
#
###
##########
#########
########
#######
######
#####
####
###
##
#
####
##########
#########
########
#######
######
#####
####
###
##
#
#####
##########
#########
########
#######
######
#####
####
###
##
#
######
##########
#########
########
#######
######
#####
####
###
##
#
#######
##########
#########
########
#######
######
#####
####
###
##
#
########
##########
#########
########
#######
######
#####
####
###
##
#
#########
##########
#########
########
#######
######
#####
####
###
##
#
>>> date = '11/23/2016'
>>> date_list = date.split()
>>> print('Month:', date_list[0])
Month: 11/23/2016
>>> print('Month:', date_list[1])
Traceback (most recent call last):
  File "<pyshell#232>", line 1, in <module>
    print('Month:', date_list[1])
IndexError: list index out of range
>>> date_list = ddate.split('/')
Traceback (most recent call last):
  File "<pyshell#233>", line 1, in <module>
    date_list = ddate.split('/')
NameError: name 'ddate' is not defined
>>> date_list = date.split('/')
>>> print('Month:', date_list[0])
Month: 11
>>> print('Day:', date_list[1])
Day: 23
>>> print('Year:', date_list[2])
Year: 2016
>>> list3
Traceback (most recent call last):
  File "<pyshell#238>", line 1, in <module>
    list3
NameError: name 'list3' is not defined
>>> fruits = 'oranges', 'apples', 'bananas', 'pears'
>>> fruit.sort()
Traceback (most recent call last):
  File "<pyshell#240>", line 1, in <module>
    fruit.sort()
NameError: name 'fruit' is not defined
>>> fruits.sort()
Traceback (most recent call last):
  File "<pyshell#241>", line 1, in <module>
    fruits.sort()
AttributeError: 'tuple' object has no attribute 'sort'
>>> fruits.split()
Traceback (most recent call last):
  File "<pyshell#242>", line 1, in <module>
    fruits.split()
AttributeError: 'tuple' object has no attribute 'split'
>>> fruits = ['oranges', 'apples', 'bananas', 'pears']
>>> fruits.sort()
>>> fruits
['apples', 'bananas', 'oranges', 'pears']
>>> if 'Pineapples' in fruits:
	print("Already in the list")
else:
	fruits+'PineApples'

	
Traceback (most recent call last):
  File "<pyshell#250>", line 4, in <module>
    fruits+'PineApples'
TypeError: can only concatenate list (not "str") to list
>>> if 'Pineapples' in fruits:
	print("Already in the list")
else:
	fruits.append('Pineapples')

	
>>> fruits
['apples', 'bananas', 'oranges', 'pears', 'Pineapples']
>>> fruits.split()
Traceback (most recent call last):
  File "<pyshell#254>", line 1, in <module>
    fruits.split()
AttributeError: 'list' object has no attribute 'split'
>>> ' '.join(fruits)
'apples bananas oranges pears Pineapples'
>>> fruits
['apples', 'bananas', 'oranges', 'pears', 'Pineapples']
>>> fruits = ' '.join(fruits)
>>> fruits+'Watermelon'
'apples bananas oranges pears PineapplesWatermelon'
>>> fruits+' Watermelon'
'apples bananas oranges pears Pineapples Watermelon'
>>> string4
Traceback (most recent call last):
  File "<pyshell#260>", line 1, in <module>
    string4
NameError: name 'string4' is not defined
>>> string4 = 'cubs crawl catching championship win.'
>>> count = 0
>>> for ch in string4:
	if ch == 'c':
		count+=1
	print('The letter "c" appears', count, "times")

	
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
>>> for ch in string4:
	if ch == 'c':
		count+=1
		print('The letter "c" appears', count, "times")

		
The letter "c" appears 6 times
The letter "c" appears 7 times
The letter "c" appears 8 times
The letter "c" appears 9 times
The letter "c" appears 10 times
>>> for ch in string4:
if ch == 'c':
	count+=1
print('The letter "c" appears', count, "times")
SyntaxError: expected an indented block
>>> 
>>> for ch in string4:
	if ch == 'c':
		count+=1
print('The letter "c" appears', count, "times")
SyntaxError: invalid syntax
>>> for ch in string4:
	if ch == 'c':
		count+=1
	print('The letter "c" appears', count, "times")

	
The letter "c" appears 11 times
The letter "c" appears 11 times
The letter "c" appears 11 times
The letter "c" appears 11 times
The letter "c" appears 11 times
The letter "c" appears 12 times
The letter "c" appears 12 times
The letter "c" appears 12 times
The letter "c" appears 12 times
The letter "c" appears 12 times
The letter "c" appears 12 times
The letter "c" appears 13 times
The letter "c" appears 13 times
The letter "c" appears 13 times
The letter "c" appears 14 times
The letter "c" appears 14 times
The letter "c" appears 14 times
The letter "c" appears 14 times
The letter "c" appears 14 times
The letter "c" appears 14 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
The letter "c" appears 15 times
>>> count - 0
15
>>> count = 0
>>> for ch in string4:
	if ch == 'c':
		count+=1
	print('The letter "c" appears', count, "times")

	
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
>>> for ch in string4:
	if ch == 'c':
		count+=1
print('The letter "c" appears', count, "times")
SyntaxError: invalid syntax
>>> for ch in string4:
	if ch == 'c':
		count+=1
		
print('The letter "c" appears', count, "times")
SyntaxError: invalid syntax
>>> strin44
Traceback (most recent call last):
  File "<pyshell#281>", line 1, in <module>
    strin44
NameError: name 'strin44' is not defined
>>> string4
'cubs crawl catching championship win.'
>>> for ch in string4:
	if ch == 'c':
		count+=1
			print('The letter "c" appears', count, "times")
			
SyntaxError: unexpected indent
>>> for ch in string4:
	if ch == 'c':
		count+=1
		print('The letter "c" appears', count, "times")

		
The letter "c" appears 6 times
The letter "c" appears 7 times
The letter "c" appears 8 times
The letter "c" appears 9 times
The letter "c" appears 10 times
>>> count = 0
>>> for ch in string4:
	if ch == 'c':
		count+=1
		print('The letter "c" appears', count, "times")

		
The letter "c" appears 1 times
The letter "c" appears 2 times
The letter "c" appears 3 times
The letter "c" appears 4 times
The letter "c" appears 5 times
>>> count = 0
>>> for ch in string4:
	if ch == 'c':
	count+=1
	print('The letter "c" appears', count, "times")
	
SyntaxError: expected an indented block
>>> for ch in string4:
	if ch == 'c':
		count+=1
	print('The letter "c" appears', count, "times")

	
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 1 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 2 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 3 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 4 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
The letter "c" appears 5 times
>>> #losing my head
>>> for ch in string4:
	if ch == 'c' or ch == 'C':
		count+=1
	print('The letter "c" appears', count, "times")

	
The letter "c" appears 6 times
The letter "c" appears 6 times
The letter "c" appears 6 times
The letter "c" appears 6 times
The letter "c" appears 6 times
The letter "c" appears 7 times
The letter "c" appears 7 times
The letter "c" appears 7 times
The letter "c" appears 7 times
The letter "c" appears 7 times
The letter "c" appears 7 times
The letter "c" appears 8 times
The letter "c" appears 8 times
The letter "c" appears 8 times
The letter "c" appears 9 times
The letter "c" appears 9 times
The letter "c" appears 9 times
The letter "c" appears 9 times
The letter "c" appears 9 times
The letter "c" appears 9 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
The letter "c" appears 10 times
>>> 
