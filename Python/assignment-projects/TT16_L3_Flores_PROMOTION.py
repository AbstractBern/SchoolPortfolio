# Bernardo Flores
# COSC1336, Lab 3, Part 2
# September 22, 2016
# Create a nested decision structure. Qualify for Crew Cook Chief
def main():
    print("This Program determine Crew Chief Promotion.")
    flip = input("Can you cook burgers (Yes/No)? ")
    fry = input("Can you fry food (Yes/No)? ")
    order = input("Can you take orders (Yes/No)? ")
    prepare = input("Can you prepare Hotdogs (Yes/No)? ")
    experience = input("Do you have more than one year of experience (Yes/No)? ")
    if ((flip and fry and order and prepare and experience)=="Yes"):
        print("You qualify for Crew Chief Promotion! Congratulations!")
    else:
        print("You do not qualify for Crew Chief Promition.")
main()
