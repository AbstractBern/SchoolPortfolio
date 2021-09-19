# Name: Bernardo Flores
# COSC1336, Lab 5a, part 3: Demonstrating local scope
# October, 24, 2016
# This program demonstrates local scopes

def main():
    number = float(int(input("Enter a number: ")))
    add_one(number)
    times_ten(number)
    less_100(number)
    print("in main. number=", number)

def add_one(number):
    modified = number + 1
    print("in add_one. number=", number, "modified=", modified)
    times_ten(modified)

def times_ten(number):
    modified = number * 10
    print("in times_ten. number=", number, "modified=", modified)
    less_100(modified)

def less_100(number):
    modified = number - 100
    print("in less_100. number=", number, "modified=", modified)
# Call the main function here.
main()
# Paste the output produced for numbers: 10, 100, 1000 below:
##Enter a number: 10
##in add_one. number= 10.0 modified= 11.0
##in times_ten. number= 11.0 modified= 110.0
##in less_100. number= 110.0 modified= 10.0
##in times_ten. number= 10.0 modified= 100.0
##in less_100. number= 100.0 modified= 0.0
##in less_100. number= 10.0 modified= -90.0
##in main. number= 10.0
##Enter a number: 100
##in add_one. number= 100.0 modified= 101.0
##in times_ten. number= 101.0 modified= 1010.0
##in less_100. number= 1010.0 modified= 910.0
##in times_ten. number= 100.0 modified= 1000.0
##in less_100. number= 1000.0 modified= 900.0
##in less_100. number= 100.0 modified= 0.0
##in main. number= 100.0
##Enter a number: 1000
##in add_one. number= 1000.0 modified= 1001.0
##in times_ten. number= 1001.0 modified= 10010.0
##in less_100. number= 10010.0 modified= 9910.0
##in times_ten. number= 1000.0 modified= 10000.0
##in less_100. number= 10000.0 modified= 9900.0
##in less_100. number= 1000.0 modified= 900.0
##in main. number= 1000.0
