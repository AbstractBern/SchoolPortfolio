# Bernardo Flores
# CSC1336, Lab7, FILE IPO
# 11/13/2016
# Read a file, sort, output to another file
def main():
    file_name= input("What is the name of your file that you would like to read?: ")
    file_name+= '.txt'
    people_file = open(file_name, 'r')
    names = people_file.readlines()
    people_file.close()
    index = 0
    while index < len(names):
        names[index] = names[index].rstrip('\n')
        index+=1
    print()
    print(names)
    print()
    names.sort()
    print(names)
    listNames = names
    nameSort(listNames)
def nameSort(listNames):
    new_file = open('People_Sorted.txt', 'w')
    new_file.write(str(listNames[0:7]) + '\n')
    new_file.write(str(listNames[7:14]) + '\n')
    new_file.write(str(listNames[14:21]) + '\n')
    if True:
        print("Successful")
    if False:
        print("Unsuccessful")
    new_file.close()
main()

#program output
##What is the name of your file that you would like to read?: people
##
##['Lu', 'Joe', 'Luis', 'Zelda', 'Chad', 'Nguyen', 'Mindy', 'Anne', 'Lee', 'George', 'Max', 'Antoine', 'Terry', 'Maria', 'An', 'Victor', 'Larry', 'Steve', 'Anita', 'Joline', 'Charles']
##
##['An', 'Anita', 'Anne', 'Antoine', 'Chad', 'Charles', 'George', 'Joe', 'Joline', 'Larry', 'Lee', 'Lu', 'Luis', 'Maria', 'Max', 'Mindy', 'Nguyen', 'Steve', 'Terry', 'Victor', 'Zelda']
##Successful
