# bernardo flores
# cosc1336 exam2 lab pt2
# 11/10/16
# re organize part1 file
def main():
    #input
    print("This program saves the amount of random numbeers in a file.")
    # Menu drivem
    while True:
        user_cmd=input('\noptions: c)reate a file(random numers); s)how a file; q)uit the program: ')
        if user_cmd in 'cC':
            user_cmd=input('\noptions: c)reate a file(random numers); s)how a file; q)uit the program: ')
            new_file = input("Enter name for a file to written to (without '.txt'): ")
            new_file+= '.txt'
            randCount = int(input("How many random numbers do you want to generage? "))
            createData(new_file, randCount)
        elif user_cmd in 'sS':
            user_cmd=input('\noptions: c)reate a file(random numers); s)how a file; q)uit the program: ')
            new_file = input("Enter name for a file to written to (without '.txt'): ")
            showData(createData)
        elif user_cmd in 'qQ':
            user_cmd=input('\noptions: c)reate a file(random numers); s)how a file; q)uit the program: ')
            print("Goodbye!")
            quit

def createData(new_file,randCount):
    #opeing file, write randcount 1, 1000
    data_file = open(new_file, 'a')
    if randCount == 0:
        quit
    else:
        for count in range(randCount):
            import random
            num = (random.randint(1, 1000))
            data_file.write(str(num) + '\n')
        if True:
            print("written successfully")
        if False:
            print("did not write successfully")
    # closing
    data_file.close()
def showData(createData):
    infile = open(new_file, 'r')
    #read lines
    for line in infile:
        amount = line
        print(format(amount, '8d'), end='')
        if True:
            print("successful")
        if False:
            print('unsuccessful')
    infile.close()

main()    
