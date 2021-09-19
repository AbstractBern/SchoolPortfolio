Python 3.5.2 (v3.5.2:4def2a2901a5, Jun 25 2016, 22:18:55) [MSC v.1900 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> month = {11: 'Novemeber', 7: 'July'}
>>> motnh[1]
Traceback (most recent call last):
  File "<pyshell#1>", line 1, in <module>
    motnh[1]
NameError: name 'motnh' is not defined
>>> month[1]
Traceback (most recent call last):
  File "<pyshell#2>", line 1, in <module>
    month[1]
KeyError: 1
>>> month[11]
'Novemeber'
>>> month = {11: 'November', 7: 'July'}
>>> month+={1: 'January'}
Traceback (most recent call last):
  File "<pyshell#5>", line 1, in <module>
    month+={1: 'January'}
TypeError: unsupported operand type(s) for +=: 'dict' and 'dict'
>>> month.append{1: 'January'}
SyntaxError: invalid syntax
>>> month.pickle{1: 'January'}
SyntaxError: invalid syntax
>>> set = {10,23,12,17}
>>> set1
Traceback (most recent call last):
  File "<pyshell#9>", line 1, in <module>
    set1
NameError: name 'set1' is not defined
>>> set1.add('Fred')
Traceback (most recent call last):
  File "<pyshell#10>", line 1, in <module>
    set1.add('Fred')
NameError: name 'set1' is not defined
>>> set1 = {10,23,12,17}
>>> del set
>>> set.add('Fred')
Traceback (most recent call last):
  File "<pyshell#13>", line 1, in <module>
    set.add('Fred')
TypeError: descriptor 'add' requires a 'set' object but received a 'str'
>>> set1.add('Fred')
>>> list1 = [[2,4,6,8]. 'here is a little list', 100,600,800]
SyntaxError: invalid syntax
>>> list1 = [[2,4,6,8], 'here is a little list', 100,600,800]
>>> list1 = [[2,4,6,8], 'here is a little list', 100,200,300]
>>> list1
[[2, 4, 6, 8], 'here is a little list', 100, 200, 300]
>>> out_object = open("junk.txt", 'w')
>>> out_object.write('List of things\n')
15
>>> import pickle
>>> out_data = oen('objects, 'b')
	       
SyntaxError: EOL while scanning string literal
>>> out_data = open('stuff.obj', 'wb')
>>> pickle.dump(out_data, month)
Traceback (most recent call last):
  File "<pyshell#24>", line 1, in <module>
    pickle.dump(out_data, month)
TypeError: file must have a 'write' attribute
>>> pickle.dump(month, out_data)
>>> pickle.dump(list1, out_data)
>>> pickle.dump(moth, out_data)
Traceback (most recent call last):
  File "<pyshell#27>", line 1, in <module>
    pickle.dump(moth, out_data)
NameError: name 'moth' is not defined
>>> pickle.dump(month, out_data)
>>> pickle.dump(list1, out_data)
>>> in_file.open('stuff.obj', 'rb')
Traceback (most recent call last):
  File "<pyshell#30>", line 1, in <module>
    in_file.open('stuff.obj', 'rb')
NameError: name 'in_file' is not defined
>>> obj1 = pickle.load(in_file)
Traceback (most recent call last):
  File "<pyshell#31>", line 1, in <module>
    obj1 = pickle.load(in_file)
NameError: name 'in_file' is not defined
>>> in_file=open('stuff.obj', 'rb')
>>> obj1 = pickle.load(in_file)
Traceback (most recent call last):
  File "<pyshell#33>", line 1, in <module>
    obj1 = pickle.load(in_file)
EOFError: Ran out of input
>>> del obj1
Traceback (most recent call last):
  File "<pyshell#34>", line 1, in <module>
    del obj1
NameError: name 'obj1' is not defined
>>> object1 = pickle.load(in_file)
Traceback (most recent call last):
  File "<pyshell#35>", line 1, in <module>
    object1 = pickle.load(in_file)
EOFError: Ran out of input
>>> ACC = 'Northridge'
>>> def upper(str):
	for ch in str:
		out+=ch.upper()

>>> 
>>> def upper(str):
	out=''
	for ch in str:
		out+=ch.upper()
	return out

>>> upper(ACC)
'NORTHRIDGE'
>>> 
