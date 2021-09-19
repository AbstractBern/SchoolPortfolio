# Bernardo Flores
# CSC1336, Lab8, phonebook
# 11/13/2016
# create a database phonebook NEEDS FIXING
def main():
    #open file
    address_file = open('Phonebook.txt', 'w')
    print("Welcome to your Phonebook.")
    again = 'y'
    #every entry will be put into a file file
    while again == 'y':
        add_on = input("Name this address: ")
            #add_on is the name of the empty list
        add_on = []
        lastName = input("Enter a last name: ")
        firstName = input("Enter a first name: ")
        phone = int(input("Enter a phone number: "))
        phoneNumber = str(phone)
        add_on.append(lastName + ',   ')
        add_on.append(firstName + '   ')
        add_on.append(':' + phoneNumber)
        add_on = ' '.join(add_on)
        address_file.write(add_on + '\n')
        # appen to file instead of print
        again = input('To enter another address) y = yes, else = any key: ')
    address_file.close()
    print("...writing to file, successful")
main()

#output
##Welcome to your Phonebook.
##Name this address: list1
##Enter a last name: Flores
##Enter a first name: Bernardo
##Enter a phone number: 8302027789
##To enter another address) y = yes, else = any key: y
##Name this address: list2
##Enter a last name: Flores
##Enter a first name: Ernie
##Enter a phone number: 8302028787
##To enter another address) y = yes, else = any key: y
##Name this address: list3
##Enter a last name: Lopez
##Enter a first name: Florenec
##Enter a phone number: 8308795151
##To enter another address) y = yes, else = any key: y
##Name this address: list4
##Enter a last name: Rodriguez
##Enter a first name: ELliot
##Enter a phone number: 8305127187
##To enter another address) y = yes, else = any key: 
##...writing to file, successful
