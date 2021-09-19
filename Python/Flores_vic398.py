#!/bin/env python3
#create

data = dict{0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "ninteen", 20: "twenty", 21: "twenty one", 22: "twenty two", 23: "twenty three", 24: "twenty four", 25: "twenty five", 26: "twenty six", 27: "twenty seven", 28: "twenty eight", 29: "twenty nine", 30: "thirty", 31: "thirty one", 32: "thirty two", 33: "thirty three", 34: "thirty four", 35: "thirty five", 36: "thirty six", 37: "thirty seven", 38: "thirty eight", 39: "thirty nine", 40: "fourty one", 41: "fourty one", 42: "fourty two", 43: "fourty three", 44: "fourty four", 45: "fourty five", 46: "fourty six", 47: "fourty seven", 48: "fourty eight", 49: "fourty nine", 50: "fifty", 51: "fifty one", 52: "fifty two", 53: "fifty three", 54: "fifty four", 55: "fifty five", 56: "fifty six", 57: "fifty seven", 58: "fifty eight", 59: "fifty nine"}
def numToString(num):
    if (num < 0  and num > 59):
        return -1
    else:
        for x in range(59):
            if num == data[x]:
                return data[x]
def timeToString(hour,minute):
    if (hour < 1 and hour >23) or (minute <0 and minute > 59):
        return (0,0,'AM/PM')
    else:
        if (hour < 12):
            postF=''.join(tuple('AM'))
        else:
            postF=''.join(tuple('PM'))
        for y in range(59):
            if hour == data[y]:
                hourT =''.join(tuple( data[y]))
            if minute == data[y]:
                minueT = ''.join(tuple(data[y]))
        if (hour == 0):
            hour=''.join(tuple("zero"))
            postF=''.join(tuple('AM'))
        return hour+', '+minute', '+postF
