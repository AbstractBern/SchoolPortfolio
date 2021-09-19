#Bernardo Flores
#model make, mileage operator
def main():
    print("This program computes gas mileage.")
    user_choice = "Yes"
    while (user_choice != "No"):
        vehicle_make = input('Enter vehicle make: ')
        vehicle_model = input('Enter vehicle model: ')
        gallon_capacity = int(input("Enter gallon capacity: "))
        perMile = gallon_capacity
        miles_traveled = float(input('Enter Odometer reading: '))
        #gal_used = input('Enter gallons used: ')
        gasMileage = (miles_traveled / perMile)
        print("Here is the data you entered:\n")
        print(vehicle_make, vehicle_model, "Gallon Capacity: ", gallon_capacity)
        print("You have burned ", (format(gasMileage, '.2f')), "gallons of gas.\n")
        user_choice = input("Would you like to try again (Yes/No)? ")
main()
    
