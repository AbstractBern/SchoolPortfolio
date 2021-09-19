# Bernardo Flores
# CSC1336, Lab7, FILE IPO
# 11/13/2016
# Read a file and output to another file
# Menu drivem
def main():
    while True:
        user_cmd=input('\noptions: r)ead; w)write; i)nsert; f)ind; m)odify; s)ort; q)uit the program: ')
        if user_cmd in 'rR':
            readIt()
        elif user_cmd in 'wW':
            write()
        elif user_cmd in 'iI':
            insertName()
        elif user_cmd in 'fF':
            findName()
        elif user_cmd in 'mM':
            modify()
        elif user_cmd in 'sS':
            sortList()
        elif user_cmd in 'qQ':
            print("Goodbye")
            quit
def readIt():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    listNames = names
    print(listNames)
    print("file in list")
def write():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    print(names)
    listNames = names 
    new_file = open('People_Sorted.txt', 'w')
    new_file.write(str(listNames[0:7]) + '\n')
    new_file.write(str(listNames[7:14]) + '\n')
    new_file.write(str(listNames[14:21]) + '\n')
    if True:
        print("Successful")
    if False:
        print("Unsuccessful")
    new_file.close()
def insertName():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    listNames = names
    print(listNames)
    insertedName = input("Whata name would you like to add? ")
    if insertedName in listNames:
        print("Name already in list!")
    else:
        listNames.insert(-1, insertedName)
        print("Modified List:", listNames)
def findName():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    listNames = names
    print(listNames) 
    targetName = input("Find a name to check if it is in list: ")
    if targetName in listNames:
        print("True")
        return True
    else:
        print("False")
        return False
def sortList():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    print(names)
    names.sort()
    listNames = names
    print(listNames)
    print("Sorted")
def modify():
    file_name = input("What is the name of your file that you would like to add to?: ")
    file_name+= '.txt'
    phone_file = open(file_name, 'r')
    address = phone_file.readline()
    phone_file.close()
    question = input("are you modifying an integer(y=yes)?: ")
    if question == 'y':
        num = int(input('What number are you replacing?: '))
        result = int(input('What is the new number?: '))
    else:
        exit()
    replace = input("What name will you replace? :")
    after = input("New name: ")
    address.replace(replace, after)
main()
#program output
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: r
##What is the name of your file that you would like to read?: people
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##file in list
##
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: w
##What is the name of your file that you would like to read?: people
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##Successful
##
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: i
##What is the name of your file that you would like to read?: people
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##Whata name would you like to add? Bernie
##Modified List: ['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen',
##'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Bernie', 'Charles']
##
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: f
##What is the name of your file that you would like to read?: people
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##Find a name to check if it is in list: Larry
##True
##
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: s
##What is the name of your file that you would like to read?: people
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##['An', 'Anita', 'Anne', 'Antoine', 'Chad', 'Charles', 'George', 'Joe', 'Joline', 'Larry', 'Lee', 'Lu', 'Luis', 'Maria', 'Max', 'Mindy', 'Nguyen', 'Steve', 'Terry', 'Victor', 'Zelda']
##Sorted
##
##options: r)ead; w)write; i)nsert; f)ind; s)ort; q)uit the program: q
##Goodbye
