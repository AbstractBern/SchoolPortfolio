class Clock:
    def __init__(self,hr,mins,sec):
        self.__sec = hr * 60 * 60 + mins * 60 + sec

    def setSecond(self, sec):
        self.__secs = sec

    def getSeconds(self):
        return self.__sec

    def __str__(self):
        return self.__sec

    def add(self, hr, mins, sec):
        add = hr * 60 * 60 + mins * 60 + sec
        self.__sec  = add + self.__sec
        

    def sub(self, hr, mins, sec):
        sub =  hr * 60 * 60 + mins * 60 + sec
        if sub < self.__sec:
            self.__sec = self.__sec - sub
        else:
            print('Time Cannot Be Negative!')

    def setName(self, name): #??????
        self.__name = name
        
    def getName(self): #???????
        return self.__name
    
    def __str__(self):
        secs = self.__sec % 60
        temp = self.__sec // 60
        mins = temp % 60
        hr = temp // 60
        return 'seconds is ' + str(hr) + ':' + str(mins) + ':' + str(secs) + '\n'
        
def main():
    c1 = Clock(1,2,3)
    c2 = Clock(4,5,6)
    c3 = Clock(7,8,9)
    print(c1.getSeconds(),c1,c2.getSeconds(),c2,c3.getSeconds(),c3)
    print('After time is added to a clock, the resuls are: ')
    c1.add(10, 11, 12); c2.add(13, 14, 15); c3.add(16, 17, 18)
    print(c1.getSeconds(),c1,c2.getSeconds(),c2,c3.getSeconds(),c3)
    print('After time is subtracted from a clock, the results are: ')
    c1.sub(1, 2, 3); c2.sub(4, 5, 6); c3.sub(7, 8, 9)
    print(c1.getSeconds(),c1,c2.getSeconds(),c2,c3.getSeconds(),c3)
    c1.setName('wristwatch'); c2.setName ('hallway'); c3.setName ('grandfather')
    print(c1.getName(), c2.getName(), c3.getName())

main()
