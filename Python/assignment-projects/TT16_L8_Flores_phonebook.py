# Bernardo Flores
# COSC1336, Lab8, Phonebook
# 11/23/16
# search, replace, find strings in file.
def main():
    while True:
        user_cmd=input('\noptions: r)ead; a)dd; d)elete; m)odify; q)uit the program: ')
        if user_cmd in 'rR':
            readIt()
        elif user_cmd in 'aA':
            add()
        elif user_cmd in 'dD':
            delete()
        elif user_cmd in 'mM':
            modify()
        elif user_cmd in 'qQ':
            print("Goodbye")
            quit
def readIt():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    book_file = open(file_name, 'r')
    book_file.read
    for names in book_file:
        print(names)
    book_file.close()
def add():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    address_file = open(file_name, 'a')
    print("You are adding to this phonebook.")
    again = 'y'
    #every entry will be put into a file file
    while again == 'y':
        add_on = input("Name this address: ")
            #add_on is the name of the empty list
        add_on = []
        lastName = input("Enter a last name: ")
        firstName = input("Enter a first name: ")
        phone = int(input("Enter a phone number: "))
        phoneNumber = str(phone)
        add_on.append(lastName + ',\t')
        add_on.append(firstName + '\t')
        add_on.append(phoneNumber + '\n')
        add_on = ' '.join(add_on)
        address_file.write(add_on + '\n')
        # appen to file instead of print
        again = input('To enter another address) y = yes, else = any key: ')
    address_file.close()
    print("...writing to file, successful")
def delete():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    address_file = open(file_name, 'a')
    print("You are deleting an object to this phonebook.")
    names = address_file.readline
    for names in address_file:
        string = str(names)
        print(string)
    target = input("What are you going to delete?(insert ' at beginning and end): ")
    if target in string:
        string.replace(target, "")
    else:
        print("Your search is not in this phonebook.")
    address_file.close()
def modify():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    address_file = open(file_name, 'a')
    address_file.read
    info = []
    for names in address_file:
        info.append(names)
        again = 'y'
    new_info = ' '.join(info)
    newer_info = str(new_info)
    print(new_info)
    again = 'y'
    while again == 'y':
        before = input("(Insert ' before&after)What would you like to modify? ")
        after = input("(insert ' before&after)To what will you modifying: ")
        if before in newer_info:
            newer_info.replace(before, after)
            print('Successful')
        else:
            print("unable to modify")
            again = input('To enter another address) y = yes, else = any key: ')

main()
#output
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: r
##What is the name of your file that you would like to read?: people_phone
##Hyung,       Lu          (512) 353-3455
##
##Lewis,       Joe         564-6755
##
##Cardenas,    Luis        678-6543
##
##Lanobar,     Zelda       672-1232 x1004
##
##Madonna                  956-1234
##
##Chad,        Charles     268-0221
##
##Nguyen       Phat        566-4098
##
##Hestor,      Mindy       (412) 543-0098
##
##Greengables, Anne        11-32-4454-22
##
##Maxmillian,  Lee
##
##Micheals,    George      (911) 411-9110
##
##Factor,      Max         753-9581
##
##DeBoies,     Antoine     655-9487
##
##Arnold
##
##Cher                     (694) 902-1044
##
##Garza,       Terry        
##
##Postelwaite, Maria
##
##Lee,         An          776-2654
##
##Suarez,      Victor
##
##Edmann,      Larry       398-8394
##
##Bishop,      Steve       909-3245
##
##Hobbes,      Anita       493-5833
##
##Webster,     Joline      583-223
##
##Fiat,        Charles     (800) 452-1001
##
##Flores,	 Bernardo	 8302027789
##
##
##
##
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: a
##What is the name of your file that you would like to read?: people_phone
##You are adding to this phonebook.
##Name this address: random
##Enter a last name: Gigger
##Enter a first name: Ramsey
##Enter a phone number: 8300288890
##To enter another address) y = yes, else = any key: n
##...writing to file, successful
##
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: 
##What is the name of your file that you would like to read?: 
##Traceback (most recent call last):
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 89, in <module>
##    main()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 9, in main
##    readIt()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 22, in readIt
##    book_file = open(file_name, 'r')
##FileNotFoundError: [Errno 2] No such file or directory: '.txt'
##
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: d
##What is the name of your file that you would like to read?: people_phone
##You are deleting an object to this phonebook.
##Traceback (most recent call last):
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 89, in <module>
##    main()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 13, in main
##    delete()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 57, in delete
##    for names in address_file:
##io.UnsupportedOperation: not readable
##
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: m
##What is the name of your file that you would like to read?: people_phone
##Traceback (most recent call last):
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 89, in <module>
##    main()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 15, in main
##    modify()
##  File "C:/Users/Bernardo Floes/Documents/COSC Labs/phonebook2.py", line 72, in modify
##    for names in address_file:
##io.UnsupportedOperation: not readable
##
##options: r)ead; a)dd; d)elete; m)odify; q)uit the program: q
##Goodbye
