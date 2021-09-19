# Bernardo Flores
# COSC1336, Lab5a, isPrime, Value-return, Random #'s
# October, 26, 2016
# Program uses random numbers to find prime.
import random

def main():
    import random
    prime_num = random.randint(2, 100)
    test_num = 2
    prime_count = 0
    count = 0
    while prime_count < prime_num:
        is_prime = True
        while test_num < test_num:
            if test_num % test_num == 0:
                is_prime = False
                print(prime_num, "is not prime")
            else:
                i += 1
            if is_prime:
                if prime_count%10 == 0 and prime_count != 0:
                    print()
            prime_count += 1
            count += 1
            print(count, '.', test_num, "is Prime")
        test_num += 1
    count = 0
    for x in range(10):
        count += 1
        prime_num = random.randint(2, 100)
        print(count,'.', isPrime(prime_num))
        print('------------------------')
    
def isPrime(prime_num):
    is_prime = True
    prime_count = 0
    test_num = 2
    i = 2
    while prime_count < prime_num:
        is_prime = True
        i = 2
        while i < test_num:
            if test_num % i == 0:
                is_Prime = False
                print(prime_num, "is not prime.")
        if is_prime:
            is_Prime = print(prime_num, 'not prime, no worries')
        return is_Prime
        
main()
 # program output
##1
##13 Prime, so True
##------------------------
##2
##97 Prime, so True
##------------------------
##3
##41 Prime, so True
##------------------------
##4
##12 not prime, no worries
##------------------------
##5
##25 Prime, so True
##------------------------
##6
##9 Prime, so True
##------------------------
##7
##38 not prime, no worries
##------------------------
##8
##92 not prime, no worries
##------------------------
##9
##27 Prime, so True
##------------------------
##10
##28 not prime, no worries
##------------------------
