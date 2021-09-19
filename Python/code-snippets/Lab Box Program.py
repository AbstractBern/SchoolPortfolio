#different style box program given to me by Tuan Cao
num = int(input('Enter a number:'))
while num > 0:
    if num % 2 == 0:
        for val in range(num):
            print('*' * num)
    elif num == 1:
        print('Invalid. Please Enter number greater than 0!')
    else:
        print('*' * num)
        for val in range(num-2):
##            for cols in range(num-(num-1)):
            print('*', ' '*(num-2), '*', sep='')
        print('*' * num)
    num = int(input('Enter a number:'))
#end
