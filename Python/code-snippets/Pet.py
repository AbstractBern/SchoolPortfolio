#class program
class Mammal:
    def __init__(self, species):
        self.__species = species
    
    def show_species(self):
        print("I AM",self.__species)
    def make_sound(self):
        print("GRRR")
class Dog(Mammal):
    def __init__(self):
        Mammal.__init__(self,'Dog')

    def make_sound(self):
        print("woof")

mam = Mammal('regular mammal')
mam.show_species()
mam.make_sound()
dog = Dog()
dog.show_species()
dog.make_sound()

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
