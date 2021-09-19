# Bernardo Flores
# COSC1336, Lab 3, Part 4: Seasons
# September 28, 2016
# outputs the name of the season and description.
def main():
    Winter = 1
    Spring = 2
    Summer = 3
    Fall = 4
    user_choice = "Yes"
    while (user_choice != "No"):
        print("Let me tell you about the seasons.")
        choice = int(input("Enter a number for a season."))
        if (choice == Winter):
            print("Winter: it is a cold day where a jacket.")
        elif (choice == Spring):
            print("Spring: Left over winter, and clear skies.")
        elif (choice == Summer):
            print("Summer: I am melting.")
        elif (choice == Fall):
            print("Fall: Hot in Texas. ")
        else:
            print("ERROR")
        user_choice = input("Try again (Yes/No)? ")
main()
# program output:
##Enter a number for winter: 1
##it is a cold day where a jacket.
##Enter a number for fall: 2
##Im melting!
##Enter a number for spring: 3
##beautiful nature.
##Enter a number for summer: 4
##Summer breeze makes me feel fine.
