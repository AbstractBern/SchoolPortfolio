#Bernardo Flores
#COSC1336 Exam2 Lab part2
#11/10/16
#create a file and write random numbers to the file.

print("Get file")
file_name = input("Enter your file name without '.txt': ")
file_name+= '.txt'
new_file = open(file_name, 'a')
randCount = int(input("How many random numbers do you want to generate? "))
import random
if randCount == 0:
    quit
else:
    for count in range(randCount):
        num = (random.randint(1, 1000))
        new_file.write(str(num) + '\n')
    # closing
    
    new_file.close()
    print("Your random numbers are in a file.")

#output
##Get file
##Enter your file name without '.txt': randomNum
##How many random numbers do you want to generate? 3
##Your random numbers are in a file.

##Get file
##Enter your file name without '.txt': random.txt
##How many random numbers do you want to generate? 3
##Your random numbers are in a file.
