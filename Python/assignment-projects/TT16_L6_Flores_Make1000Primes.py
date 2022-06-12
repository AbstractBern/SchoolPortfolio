# Bernardo Flores
# COSC1336, Lab6
# November 1, 2016
# File, Output, Exceptions
# Write the first 1000 primes into a text file.

# Prime is an imported file that contains the isPrime function to return 1=if prime, 0=if not prime
from Prime import isPrime

#def main():
    number = 0
    reached = 0
    primes = 0
    count = 0
    prime_file = open('1000Primes.txt', 'w')
    prime_file.write(format("The First 1,000 Primes", "^73"))
    prime_file.write("\n")
    prime_file.write(format("(the 1,000th is 7919)", "^73"))
    prime_file.write("\n\n")
    n = 1001
    while not reached:
        if isPrime(count):
            prime_file.write(format(str(count), "7s") + " ")
            primes += 1
        elif primes >= n:
            reached = 1
        count += 1
    prime_file.close()
    print('Successful')
main()
