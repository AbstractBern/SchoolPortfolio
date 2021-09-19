# bernardo Flores
# cosc1336, lab 10a-b, clock, class
#12/9/2016
# creating a clock with class
class clock:
    #mandatory init function, w/setters or getters
    def __init__(self, hour, minute, second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second
        #attributes that are in a clock
    def set_hour(self, hour):
        self.__hour=hour
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
        return "Hour=" + str(self.__hour)+','+ 'Minute=' + str(self.__minute) +','+ "Second=" + str(self.__second)
    
#print a stopwatch and clock as these numbers
stopwatch = clock(0,0,0)
print(stopwatch.__str__())
my_clock = clock(10,30,0)
print(my_clock.__str__())
test_clock = clock(34,-100,4345)
print(test_clock.__str__())
cl1 = clock(-10,223,10)
print(cl1.__str__())
#program output
##Hour=0,Minute=0,Second=0
##Hour=10,Minute=30,Second=0
##Hour=34,Minute=-100,Second=4345
##Hour=-10,Minute=223,Second=10
