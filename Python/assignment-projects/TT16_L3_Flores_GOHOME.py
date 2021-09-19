## Bernardo Flores
# COSC1336, Lab 3, Part 5, Drive Home
# Septemeber 29, 2016
# This program determines whether the user should drive home on circumstances.
def main():
    print("Should you drive home?")
    batteryChaged = True
    gotCar = True
    drunk = False
    gas_gallons = 2
    distance = 100
    mpg = 35
    nightTime = False
    headlightsOut = True
    drive_home = input("can you drive home (True/False)? ")
    if True:
        batteryCharged = input("Is battery charged (True/False)?")
        gotCar = input("Do you have a car (True/False)? ")
        gas = input("do you have more than two gallons of gas (True/False)? ")
        nighttime = ("Is it nighttime (True/False)? ")
        mpg = input("Do you have 35MPG (True/False)? ")
        disance = input("Are you 100 miles away (True/False)? ")
        headlightsOut = input("Are the headlights out (True/False)? ")
        drunk = input("are you drunk (True/False)? ")
        if (batteryCharged and gotCar and (drunk==False) and gas and nightTime and (headlightsOut==False) == True):
            print("You can drive Home.")
            #needs some work
        else
main()
