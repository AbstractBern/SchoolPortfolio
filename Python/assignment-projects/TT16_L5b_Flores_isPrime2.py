# bernardo FLores
# cosc1336 lab5a pt 2
# Halloween
# sort more than, swap

import random

def main():
    import random
    count = 0
    for x in range(10):
        count += 1
        print(count,'(Random Numbers):')
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        c = random.randint(1, 100)
        more_than(a,b)
        swap(a,b)
        sort3(a,b,c)
        print('~~~~~~~~~~~~~~~~~~~~~~')

def more_than(a,b):
    if a > b :
        print('True, A is greater.')
    else:
        print('False, A is not greataer.')

def swap(a,b):
    print("original:", a, b)
    print("Swap'd:", b, a)

def sort3(a,b,c):
    my_list = [a,b,c]
    print('Random Numbers:', my_list); my_list.sort(); print('Sort To', my_list)
    
main()

# progam output

##1 (Random Numbers):
##False, A is not greataer.
##original: 65 99
##Swap'd: 99 65
##Random Numbers: [65, 99, 18]
##Sort To [18, 65, 99]
##~~~~~~~~~~~~~~~~~~~~~~
##2 (Random Numbers):
##True, A is greater.
##original: 56 21
##Swap'd: 21 56
##Random Numbers: [56, 21, 80]
##Sort To [21, 56, 80]
##~~~~~~~~~~~~~~~~~~~~~~
##3 (Random Numbers):
##True, A is greater.
##original: 71 11
##Swap'd: 11 71
##Random Numbers: [71, 11, 11]
##Sort To [11, 11, 71]
##~~~~~~~~~~~~~~~~~~~~~~
##4 (Random Numbers):
##True, A is greater.
##original: 92 54
##Swap'd: 54 92
##Random Numbers: [92, 54, 1]
##Sort To [1, 54, 92]
##~~~~~~~~~~~~~~~~~~~~~~
##5 (Random Numbers):
##False, A is not greataer.
##original: 16 43
##Swap'd: 43 16
##Random Numbers: [16, 43, 8]
##Sort To [8, 16, 43]
##~~~~~~~~~~~~~~~~~~~~~~
##6 (Random Numbers):
##False, A is not greataer.
##original: 75 76
##Swap'd: 76 75
##Random Numbers: [75, 76, 66]
##Sort To [66, 75, 76]
##~~~~~~~~~~~~~~~~~~~~~~
##7 (Random Numbers):
##True, A is greater.
##original: 85 59
##Swap'd: 59 85
##Random Numbers: [85, 59, 30]
##Sort To [30, 59, 85]
##~~~~~~~~~~~~~~~~~~~~~~
##8 (Random Numbers):
##False, A is not greataer.
##original: 13 99
##Swap'd: 99 13
##Random Numbers: [13, 99, 89]
##Sort To [13, 89, 99]
##~~~~~~~~~~~~~~~~~~~~~~
##9 (Random Numbers):
##True, A is greater.
##original: 52 18
##Swap'd: 18 52
##Random Numbers: [52, 18, 72]
##Sort To [18, 52, 72]
##~~~~~~~~~~~~~~~~~~~~~~
##10 (Random Numbers):
##True, A is greater.
##original: 81 31
##Swap'd: 31 81
##Random Numbers: [81, 31, 82]
##Sort To [31, 81, 82]
##~~~~~~~~~~~~~~~~~~~~~~
