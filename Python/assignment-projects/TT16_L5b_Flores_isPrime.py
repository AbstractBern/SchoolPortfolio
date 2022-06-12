# Bernardo Flores
# COSC1336, Lab5a, isPrime, Value-return, Random #'s
# October, 26, 2016
# Build a function that checks to see if a number is prime. Utilize random to check a variety of numbers are prime.
import random

def isPrime(number):
    is_prime = 0
    count = 0
    start = 2
    # this blocks helps u
    for i in range(start, number//2 + 1):
        if (number % i == 0):
            count = count + 1
            break
        else:
            start = (number//2)-2
    if count == 0 and number != 1:
        is_prime = 1
    return is_prime
    
for x in range(1, 11):
    thisNumber = random.randint(2, 100)
    if isPrime(thisNumber):
        print(x ,"\n",thisNumber, '-', "is prime.")
    else:
        print(x,"\n",thisNumber, '-', "is not prime.")
    print('------------------------')
