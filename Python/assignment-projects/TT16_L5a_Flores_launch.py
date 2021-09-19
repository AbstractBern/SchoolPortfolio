# Name: Bernardo Flores
# COSC1336, Lab 5a, part 1: Rewrite launch sequence software with functions
# October 16, 2016
# Launch a rocket into space.
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
# fill tank ()
# who knew putting numb in () at main and fuel_tank would be the answer.
# Good 5 hours :)
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

# Paste your output below:
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





