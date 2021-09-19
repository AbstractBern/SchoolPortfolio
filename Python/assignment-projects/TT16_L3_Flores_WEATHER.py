# Bernardo Flores
# COSC1336, Lab 3, Part 1: Read Thermometer
# September 22, 2016
# Decision structures for Read Thermometer and Bring an Umbrella for outside.
print('This program consults your next steps for the weather.')
print("Go to your window.")
print('Read Thermometer')
# variables
thermometer = float(input('What does the Thermometer read? '))
if thermometer < 70 :
    print("It is cold outside")
    print("Bring a jacket!")
else:
    thermometer > 70
    print("It is not cold outside.")
# texas heat sunny.
sunny = input('Is there alot of sun? (y/n)')
if sunny == 'yes' :
    print("Bring shades or a hat, if you prefer.")
else :
    print("No shade needed.")
# Clouds
clouds = input('Are there heavy clouds? (y/n)')
if clouds == 'yes' :
    print("Carry umbrella incase.")
else :
    print("No umbrella needed.")
# if raining
raining = input('Is it raining? (y/n)')
if raining == 'yes' :
    print("Bring an umbrella! And Be Careful!")
else :
    print("No need for an umbrella! Enjoy mother nature.")
# get out of the house
print("Open the front door.")
print("Go outside.")
print("Carry On!")
var = input("Please enter something: ")
# Program output:
##This program consults your next steps for the weather.
##Go to your window.
##Read Thermometer
##What does the Thermometer read? 90
##It is not cold outside.
##Is there alot of sun? yes
##Bring shades or a hat, if you prefer.
##Are there heavy clouds? no
##No umbrella needed.
##Is it raining? no
##No need for an umbrella! Enjoy mother nature.
##Open the front door.
##Go outside.
##Carry On!
# Different events
##This program consults your next steps for the weather.
##Go to your window.
##Read Thermometer
##What does the Thermometer read? 50
##It is cold outside
##Bring a jacket!
##Is there alot of sun? no
##No shade needed.
##Are there heavy clouds? yes
##Carry umbrella incase.
##Is it raining? yes
##Bring an umbrella! And Be Careful!
##Open the front door.
##Go outside.
##Carry On!
