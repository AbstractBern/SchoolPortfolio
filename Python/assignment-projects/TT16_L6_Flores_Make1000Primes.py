# Bernardo Flores
# COSC1336, Lab6
# November 1, 2016
# File, Output, Exceptions

def main():
    prime_file = open('1000Primes.txt', 'w')
    prime_file.write(format("The First 1,000 Primes", "^73"))
    prime_file.write("\n")
    prime_file.write(format("(the 1,000th is 7919)", "^73"))
    prime_file.write("\n\n")
    prime_num = int(input('How many primes numbers do you want to find? :'))
    n = 1000
    test_num = 2
    prime_count = 0
    while prime_count < n:
        is_prime = True
        i = 2
        while i < test_num:
            if test_num % i == 0:
                is_prime = False
                break
            else:
                i += 1
        if is_prime:
            if prime_count%10 == 0 and prime_count != 0:
                prime_file.write("\n")
            prime_count += 1
            prime_file.write(format(str(test_num), "7s") + " ")
        test_num += 1
    prime_file.close()
    print('Successful')
main()
# File will be in '1000Primes.txt'
# Collaborated with Michael.
#This makes alot of sense now.
