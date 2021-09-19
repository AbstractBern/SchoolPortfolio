# Bernardo Flores
# COSC 1336
# October, 06 2016
# Ask the user for ACC Campus Abgrevitions

print("ACC Campuses")

input("Can you give me an ACC Campus abbreviation (yes/no) ")
if 'yes':
    campus = input('Enter a campus abbreviation: ')
    if campus == 'NRG' or 'RRC' or 'RGC' or 'CYP' or'SAC':
        housing = input("number of buildings on campus: ")
        classes = input("number of classrooms per building: ")
        seats = input("number of seats per classroom: ")
        max_capacity = int(input('How many students can attend? '))
    if max_capacity <= 4000 :
        print("The amount that can attend:", max_capacity)
    else:
        max_capacity >= 4000
        print("no more students can attend!")
else:
    exit()
    
# Program output:
##ACC Campuses
##Can you give me an ACC Campus abbreviation? yes
##Enter a campus abbreviation: RRC
##number of buildings on campus: 4
##number of classrooms per building: 14
##number of seats per classroom: 24
##How many students can attend? 4000
##The amount that can attend: 4000
##ACC Campuses
##Can you give me an ACC Campus abbreviation? yes
##Enter a campus abbreviation: CYP
##number of buildings on campus: 5
##number of classrooms per building: 15
##number of seats per classroom: 25
##How many students can attend? 4000
##The amount that can attend: 4000
##ACC Campuses
##Can you give me an ACC Campus abbreviation? yes
##Enter a campus abbreviation: ACC
##number of buildings on campus: 6
##number of classrooms per building: 16
##number of seats per classroom: 26
##How many students can attend? 3000
##The amount that can attend: 3000
