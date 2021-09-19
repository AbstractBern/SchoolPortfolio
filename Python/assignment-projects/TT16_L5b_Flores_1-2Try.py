# Bernardo F
# COSC1336, Lab5, Part1-2
# halloween
# wrap codes parts 1 and 2.
def main():
    part1()

    part2()
    
def part1():
    prime_num = int(input('How many primes numbers do you want to find? :'))
    prime_count = 0
    num=1
    col = 1
    while prime_count < prime_num:
        isPrime = True
        num+=1
        for y in range(2,num):
            if num % y==0:
                isPrime = False
                print(num
        if isPrime:
            print(format(num, "IsPrime")
            if col%10==0:
                print()
            col+=1
            prime_count+=1
        print()
    main()
def part2():
    import random
    def main():
        import random
        count = 0
        for x in range(10):
            count += 1
            print(count, '.(Random Numbers):')
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
        print('Random Numbers:', my_list); my_list.sort(); print('Sort To:', my_list)
    main()

main()
# program output
##1 .
##38 not prime, no worries
##~~~~~~~~~~~~~~~~~~~~~~~
##2 .
##3 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##3 .
##22 not prime, no worries
##~~~~~~~~~~~~~~~~~~~~~~~
##4 .
##55 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##5 .
##80 not prime, no worries
##~~~~~~~~~~~~~~~~~~~~~~~
##6 .
##97 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##7 .
##51 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##8 .
##48 not prime, no worries
##~~~~~~~~~~~~~~~~~~~~~~~
##9 .
##51 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##10 .
##17 Prime, so True
##~~~~~~~~~~~~~~~~~~~~~~~
##1 .(Random Numbers):
##True, A is greater.
##original: 60 52
##Swap'd: 52 60
##Random Numbers: [60, 52, 32]
##Sort To: [32, 52, 60]
##~~~~~~~~~~~~~~~~~~~~~~
##2 .(Random Numbers):
##True, A is greater.
##original: 100 94
##Swap'd: 94 100
##Random Numbers: [100, 94, 77]
##Sort To: [77, 94, 100]
##~~~~~~~~~~~~~~~~~~~~~~
##3 .(Random Numbers):
##False, A is not greataer.
##original: 26 76
##Swap'd: 76 26
##Random Numbers: [26, 76, 57]
##Sort To: [26, 57, 76]
##~~~~~~~~~~~~~~~~~~~~~~
##4 .(Random Numbers):
##True, A is greater.
##original: 79 35
##Swap'd: 35 79
##Random Numbers: [79, 35, 86]
##Sort To: [35, 79, 86]
##~~~~~~~~~~~~~~~~~~~~~~
##5 .(Random Numbers):
##True, A is greater.
##original: 96 92
##Swap'd: 92 96
##Random Numbers: [96, 92, 64]
##Sort To: [64, 92, 96]
##~~~~~~~~~~~~~~~~~~~~~~
##6 .(Random Numbers):
##False, A is not greataer.
##original: 10 100
##Swap'd: 100 10
##Random Numbers: [10, 100, 68]
##Sort To: [10, 68, 100]
##~~~~~~~~~~~~~~~~~~~~~~
##7 .(Random Numbers):
##False, A is not greataer.
##original: 44 86
##Swap'd: 86 44
##Random Numbers: [44, 86, 14]
##Sort To: [14, 44, 86]
##~~~~~~~~~~~~~~~~~~~~~~
##8 .(Random Numbers):
##True, A is greater.
##original: 100 93
##Swap'd: 93 100
##Random Numbers: [100, 93, 73]
##Sort To: [73, 93, 100]
##~~~~~~~~~~~~~~~~~~~~~~
##9 .(Random Numbers):
##False, A is not greataer.
##original: 36 82
##Swap'd: 82 36
##Random Numbers: [36, 82, 98]
##Sort To: [36, 82, 98]
##~~~~~~~~~~~~~~~~~~~~~~
##10 .(Random Numbers):
##False, A is not greataer.
##original: 59 98
##Swap'd: 98 59
##Random Numbers: [59, 98, 38]
##Sort To: [38, 59, 98]
##~~~~~~~~~~~~~~~~~~~~~~
