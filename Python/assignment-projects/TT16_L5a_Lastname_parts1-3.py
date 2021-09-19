# Bernardo Flores
# COSC1336 Lab5: part1-3 wrapping
# October 25, 2016
# creats a menu driven program
def launch():
    def main():
        print("This program launches a rocket.")
        fuel_tank(1)
        fuel_tank(2)
        fuel_tank(3)
        engine(1)
        engine(2)
        print("To start launch sequence:")
        input("Press enter to begin the launch sequence...")
        count_down()
        # locate your function calls here in main.
    def fuel_tank(numb):
        print('Fill booster fuel tank', numb)
        print("  open valve")
        print("  pre-freeze tank")
        print("  attach filler hose")
        print("  pressurize fuel supply")
        print("  fill tank")
        print("  secure and seal shutoff valve")
    def engine(num):
        print("Start engine", num)
        print("  ignition sequence start")
        print("  start ignition spark generator")
        print("  open fuel valve")
        print("  verify ignition temperature")
        print("  stop ignition spark generator")
        print("  engine 1 is started")
    def count_down():
        print("3, 2, 1, 0, BLASTOFF!!!")
        print("Thank you. Keep looking up!")
        
    main()
def tip_table():
    def display_total_due(bill_with_tax, tip_rate, tax_rate):
        tax_rate = 0.0825
        bill_without_tax = bill_with_tax / (1 + tax_rate)
        tip = bill_without_tax * tip_rate
        total_due = bill_with_tax + tip
        print("Total due with ", tip_rate, "% tip: ", format(total_due, '.2f'))

    # Add a main function here
    def main():
        bill_with_tax = float(input('enter the bill with tax: '))
        tax_rate = 0.0825
        display_total_due(bill_with_tax, 0.10, tax_rate)
        display_total_due(bill_with_tax, 0.15, tax_rate)
        display_total_due(bill_with_tax, 0.20, tax_rate)
        display_total_due(bill_with_tax, 0.25, tax_rate) 
    main()

def scope():
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
def main():
    print("Hello, welcome to the menu driven progam.")
    while True:
        user_cmd=input('\noptions: l)aunch; t)ip_table; s)cope q)uit: ')
        if user_cmd in 'lL':
          launch()    
        elif user_cmd in 'qQ':
          break
        elif user_cmd in 'tT':
          tip_table()
        elif user_cmd in 'sS':
          scope()      
        else:
          print('  sorry, this is an invalid option, try again.')

    print('Goodbye.')
main()
# program output
##Hello, welcome to the menu driven progam.
##
##options: l)aunch; t)ip_table; s)cope q)uit: l
##This program launches a rocket.
##Fill booster fuel tank 1
##  open valve
##  pre-freeze tank
##  attach filler hose
##  pressurize fuel supply
##  fill tank
##  secure and seal shutoff valve
##Fill booster fuel tank 2
##  open valve
##  pre-freeze tank
##  attach filler hose
##  pressurize fuel supply
##  fill tank
##  secure and seal shutoff valve
##Fill booster fuel tank 3
##  open valve
##  pre-freeze tank
##  attach filler hose
##  pressurize fuel supply
##  fill tank
##  secure and seal shutoff valve
##Start engine 1
##  ignition sequence start
##  start ignition spark generator
##  open fuel valve
##  verify ignition temperature
##  stop ignition spark generator
##  engine 1 is started
##Start engine 2
##  ignition sequence start
##  start ignition spark generator
##  open fuel valve
##  verify ignition temperature
##  stop ignition spark generator
##  engine 1 is started
##To start launch sequence:
##Press enter to begin the launch sequence...
##3, 2, 1, 0, BLASTOFF!!!
##Thank you. Keep looking up!
##
##options: l)aunch; t)ip_table; s)cope q)uit: t
##enter the bill with tax: 10.82
##Total due with  0.1 % tip:  11.82
##Total due with  0.15 % tip:  12.32
##Total due with  0.2 % tip:  12.82
##Total due with  0.25 % tip:  13.32
##
##options: l)aunch; t)ip_table; s)cope q)uit: s
##Enter a number: 10
##in add_one. number= 10.0 modified= 11.0
##in times_ten. number= 11.0 modified= 110.0
##in less_100. number= 110.0 modified= 10.0
##in times_ten. number= 10.0 modified= 100.0
##in less_100. number= 100.0 modified= 0.0
##in less_100. number= 10.0 modified= -90.0
##in main. number= 10.0
##
##options: l)aunch; t)ip_table; s)cope q)uit: q
##Goodbye.

