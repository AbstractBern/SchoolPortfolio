# Bernardo Flores
# COSC1336, Lab6
# November 1, 2016
# File, Output, Exceptions

def main():
    max_pop = " "
    min_pop = " "
    popTotal = 0
    all_states = 0
    state_file = open("StateCensus2010.txt", "r")
    print("Calculates Data from Census File")
    state= state_file.readline() 
    while state != "": 
        state = state.rstrip("\n")
        abbrev = state_file.readline() # State Abbreviation
        abbrev = abbrev.rstrip("\n")
        state_pop = int(state_file.readline()) # State Population
        if max_pop == " " or state_pop > max_pop:
            max_pop = state_pop
            max_state = state
        if min_pop == " " or state_pop < min_pop:
            min_pop = state_pop
            min_state = state
        if state == "Texas":
            texas_pop = state_pop
        if state != "":
            state_name = state
            popTotal += state_pop
            all_states += 1
        state = state_file.readline() # State Name
    avg_pop = int(popTotal/all_states)
    print("Maximum Population: ", format(max_pop, ",")," in ", max_state, ".", sep="")
    print("Minimum Population: ", format(min_pop, ",")," in ", min_state, ".", sep="")
    print("Average of State Population: ", format(avg_pop, ","), ".", sep="")
    print("The population in Texas is ", format(texas_pop, ","), ".", sep="")

main()
# little bit of collaboration with peer.
#program output
##Calculates Data from Census File
##Maximum Population: 37,341,989 in California.
##Minimum Population: 568,300 in Wyoming.
##Average of State Population: 6,181,559.
##The population in Texas is 25,268,418.


