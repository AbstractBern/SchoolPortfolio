#class program
class Pet:
    def __init__(self,name,animal_type,age):
        self.__name = name
        self.__animal_type=animal_type
        self.__age=age
    def set_name(self,name):
        self.__name=name
    def set_animal_type(self,animal_type):
        self.__animal_type=animal_type
    def set_age(self,age):
        self.__age=age
    def get_name(self):
        return self.__name
    def get_animal_type(self):
        return self.__animal_type
    def get_age(self):
        return self.__age
def main():
    entry = input('Name This: ')
    
    print('Enter Your Pets Information.')
    name = input('Name: ')
    animal_type = input('What type of animal is your pet? ')
    age = float(int(input('What is your pets age? ')))
    entry = Pet(name,animal_type,age)
    print('Here is the data you entered:')
    print('Name: ',entry.get_name())
    print('Animal Type: ',entry.get_animal_type())
    print('Age: ',entry.get_age())
main()
