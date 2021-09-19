# bernardo Flores
# cosc1336, lab 10b, clock, class
# 12/9/2016
# build clock to use just seconds within class 
# bernardo Flores
# cosc1336, lab 10b, clock, class
# 12/9/2016
# build clock to use just seconds within class 
class clock:
    #mandatory init function, w/setters or getters
    def __init__(self, hour, minute, second):
        if hour in range(1,25):
            self.__hour = hour
        else:
            self.__hour=0
        if minute in range(0,60):
            self.__minute = minute
        else:
            self.__minute= 0
        if second in range(0,60):
            self.__second = second
        else:
            self.__second = 0
        #attributes that are in a clock

    def set_second(self,hour,minute,second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second
    def get_second(self):
        return self.__hour
        return self.__minute
        return self.__second
    #return inputs as string
    def __str__(self):
        sunDial = 'AM'
        if hour >=12:
            sunDial ='PM'
        return str(self.__hour)+':'+ str(self.__minute) +':'+ str(self.__second)+sunDial
#result in seconds
try:
    print('Return my time in total seconds')
    hour = int(input('Enter a hour: '))
    minute = int(input('Enter a minute: '))
    second = int(input('Enter seconds: '))
except ValueError:
    print("Enter only numbers.")

clock_seconds = clock(hour,minute,second)
print('Clock: ',clock_seconds.__str__())
