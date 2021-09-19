import vehicles
#Note
#this imports superclass and subclass for instances
#THIS IS AN INHERITANCE EXAMPLE
#an instance is where different variables but they equal different results
#of an object/class
#such coin1=coin.coin()
#methods-accessor returns information that cant be accessed outside
#method mutator gets and manipulates incoming info
#pickle wb or just file 'a' and write onto them
#POLYMORPHISM IS LIKE DOING HIERARCHY AND SUBFUN AND FUN
#BUT INSIDE A CLASS AND SPREADING CLASSES INTO DIFFERENT
#P = THIS
#V = THAT
#P.MESSAGE() #EACH CAN BE FOUND IN THERE SUB CLASS BUT HAVE SIMILAR AREAS IN
# the SUPERIOR CLASS
#V.MESSAGE
def main():
    #create an object
    used_car = vehicles.Car('Audi','2007','12,500','21,500.00','4')
    print('Make: ',used_car.get_make())
    print('Model: ',used_car.get_model())
    print('Mileage: ',used_car.get_mileage())
    print('Price: ',used_car.get_price())
    print('Number of Doors: ',used_car.get_doors())

    this = input('Enter a name for this car: ')
    make = input('Enter make of vehicle; ')
    model = input('Enter a model for this car: ')
    mileage = input('Enter the mileage: ')
    price = input('Enter price: ')
    doors = input('How many doors: ')
    this = vehicles.Car(make,model,mileage,price,doors)
    print('Make: ',this.get_make())
    print('Model: ',this.get_model())
    print('Mileage: ',this.get_mileage())
    print('Price: ',this.get_price())
    print('Number of Doors: ',this.get_doors())
main()
