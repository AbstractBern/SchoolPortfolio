# Bernardo Flores
# COSC 1336
# October, 06 2016.
# This prgram computes the enrollment capacity for an ACC Campus

print("Program computes enrollment capacity for an ACC Campus.")

detail = input('would you like to display detailed instructions? (d)')
if detail == 'd':
    campus = input('Enter a campus abbreviation: ')
    if campus == 'NRG' or 'RRC' or 'RGC' or 'CYP' or'SAC':
        housing = input("number of buildings on campus: ")
        classes = input("number of classrooms per building: ")
        seats = input("number of seats per classroom: ")
        ave = input("What is the average of classrooms? ")
        ave2 = input("What is the average of seats per classroom? ")
else:
    calc = input('would you like to calculate the max capacity for ACC? (c)')
    if calc == 'c':
        maxCap = int(input("How many students can ACC serve? "))
        print('Capacity to the max:', maxCap)
        total_people=0
people=int(input("please enter the max capacity in each campus: (<0 to quit)"))
while people>=0:
  total_people += people # works, better this way!!!  
  people=int(input("please enter the max capacity in each campus: (<0 to quit)"))
print("total capacity=", total_people)  
if calc == 'no':
        print('quit program')
# Test output:
##Program computes enrollment capacity for an ACC Campus.
##would you like to display detailed instructions? (d)d
##Enter a campus abbreviation: NRG
##number of buildings on campus: 12
##number of classrooms per building: 24
##number of seats per classroom: 25
##What is the average of classrooms? 23
##What is the average of seats per classroom? 25
##Program computes enrollment capacity for an ACC Campus.
##would you like to display detailed instructions? (d)no
##would you like to calculate the max capacity for ACC? (c)c
##How many students can ACC serve? 4000
##Capacity to the max: 4000
##Program computes enrollment capacity for an ACC Campus.
##would you like to display detailed instructions? (d)no
##would you like to calculate the max capacity for ACC? (c)no
