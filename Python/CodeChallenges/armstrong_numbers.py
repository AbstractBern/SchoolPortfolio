
import sys
import math
lent = len(sys.argv)
total = 0
for i in range(1,lent):
    numLen = len(sys.argv[i])
    dig = sys.argv[i]
    for x in range(0,len(dig)):
        num = dig[x]
        total += pow(int(num),numLen)
    if total == int(dig):
        print("True ",dig, total," - Armstrong #")
    else:
        print("False ",dig, total," - Not Armstrong #")
    total = 0
    #3*3*3 + 5*5*5 + 1*1*1 = 351
    #1*1*1 + 5*5*5 + 3*3*3
