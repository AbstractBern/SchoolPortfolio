# Bernard FLores
# COSC1336, Lab 9
# 12/5/16
# create a dictionary from state census file.
# search for state by abbreviation
file = open('StateCensus2010.txt', 'r')
#dict. empty
stateDict = {}
line1 = file.readline()
# loop to readline
while line1 != '':
    line2 = file.readline()
    line3 = file.readline()
    # strips '\n' from lines
    stateDict[line2.rstrip('\n')] = line1.rstrip('\n')
    line1 = file.readline()
stateDict
#most work done
file.close()
#loop for user 
find = 'y'
print('Find State by Abbrev.')
while find == 'y':
    state = input('Enter abbreviation for State: ')
    # kind interface, if lowecase: forms into uppercase
    # tried to switch the char of abbrev if either was lower. FAILED
    if state.islower() == True:
        state = state.upper()
    print(stateDict.get(state))
    find = input("Want to find a state: Enter 'y'. If not: Enter 'q'.")
    #structure:answer y or q if ANYTHING ELSE error message and breaks
    if find == 'y':
        continue
    elif find == 'q':
        quit()
    else:
        print('ERROR: Try Again')
        break
    
# program output
##Find State by Abbrev.
##Enter abbreviation for State: AL
##Alabama
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: AK
##Alaska
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: AZ
##Arizona
##Want to find a state: Enter 'y'. If not: Enter 'q'.y 
##Enter abbreviation for State: AR
##Arkansas
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: CA
##California
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: CO
##Colorado
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: CT
##Connecticut
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: DE
##Delaware
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: FL
##Florida
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: GA
##Georgia
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: Hi
##None
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: HI
##Hawaii
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: ID
##Idaho
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: IL
##Illinois
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: IN
##Indiana
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: IA
##Iowa
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: KS
##Kansas
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: KY
##Kentucky
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: LA
##Louisiana
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: ME
##Maine
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MD
##Maryland
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MA
##Massachusetts
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MI
##Michigan
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MN
##Minnesota
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MS
##Mississippi
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MO
##Missouri
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: MT
##Montana
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NE
##Nebraska
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NV
##Nevada
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NH
##New Hampshire
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NJ
##New Jersey
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NM
##New Mexico
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NW
##None
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: NC
##North Carolina
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: ND
##North Dakota
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: OH
##Ohio
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: OK
##Oklahoma
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: OR
##Oregon
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: PA
##Pennsylvania
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: RI
##Rhode Island
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: SC
##South Carolina
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: SD
##South Dakota
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: TN
##Tennessee
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: TX
##Texas
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: UT
##Utah
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: VT
##Vermont
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: VA
##Virginia
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: WA
##Washington
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: WV
##West Virginia
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: WI
##Wisconsin
##Want to find a state: Enter 'y'. If not: Enter 'q'.y
##Enter abbreviation for State: WY
##Wyoming
##Want to find a state: Enter 'y'. If not: Enter 'q'.
##ERROR: Try Again
##Want to find a state: Enter 'y'. If not: Enter 'q'.Y
##ERROR: Try Again
