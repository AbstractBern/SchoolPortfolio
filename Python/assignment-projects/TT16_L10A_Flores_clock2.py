# bernardo Flores
# cosc1336, lab 10a-b, clock, class
#12/9/2016
# creating a clock with class modified
class clock:
    #mandatory init function, w/setters or getters
    def __init__(self, __hour, __minute, __second):
        if __hour in range(1,25):
            self.__hour = __hour
        else:
            self.__hour=0
        if __minute in range(0,60):
            self.__minute = __minute
        else:
            self.__minute= 0
        if __second in range(0,60):
            self.__second = __second
        else:
            self.__second = 0
        #attributes that are in a clock
    def set_hour(self, hour):
        self.__hour = hour
    def set_minute(self, minute):
        self.__minute = minute
    def set_second(self, second):
        self.__second = second
    def get_hour(self):

        return self.__hour
    def get_minute(self):
        return self.__minute
    def get_second(self):
        return self.__second
    #return inputs as string
    def __str__(self):
        time_setting = 'AM'
        if self.__hour>=12:
            time_setting = 'PM'
        return str(self.__hour)+':'+ str(self.__minute) +':'+ str(self.__second)+time_setting
    
#print a stopwatch and clock as these numbers
stopwatch = clock(0,0,0)
print(stopwatch.__str__())
my_clock = clock(10,30,0)
print(my_clock.__str__())
test_clock = clock(34,-100,4345)
print(test_clock.__str__())
cl1 = clock(-10,223,10)
print(cl1.__str__())
print('more')
time1 = clock(24,59,10)
time2 = clock(5,46,59)
print(time1.__str__())
print(time2.__str__())
try:
    hour = int(input('Enter hour: '))
    minute = int(input('Enter minute: '))
    sec = int(input('Enter second '))
    print(clock(hour,minute,sec))
except ValueError:
    print('wrong entry')
#program output
##0:0:0AM
##10:30:0AM
##0:0:0AM
##0:0:10AM
##more
##24:59:10PM
##5:46:59AM
##Enter hour: 12
##Enter minute: 13
##Enter second 32
##12:13:32PM
