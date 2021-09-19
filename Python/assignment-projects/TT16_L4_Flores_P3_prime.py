-# bernardo flores
# cosc1336, Lab 4 retry, reconsider
# 12/16/2016
# boxes
start =2
for count in range(7):
    start+=1
print(start)
start = 0
for count in range(3):
    start+=3
print(start)
start =2
for count in range(7):
    start*=1
print(start)
start = 0
for count in range(3):
    start*=3
print(start)
print('Entering primes.')
num = int(input('Enter a number: '))
test_num = 2
prime_count = 0
while prime_count < num:
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
            print()
        prime_count +=1
        print(test_num)
    test_num+=1
    print('done')
