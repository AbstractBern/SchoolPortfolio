# Bernardo Flores
# COSC1336, Lab 3, Part 3
# September 25, 2016
# This program determines the winner of a Rock-Paper-Scissors Game made to 
# study nested conditions, however, this can be done in half the lines of code
choices = ('rock', 'paper', 'Scissors')
print(("Game of " + ', '.join(choices)).upper())
while True:
    player1 = input("Player1 - Choose [rock/paper/scissors] [q - Quit]: ")
    if player1 == 'q':
        break
    player2 = input("Player 2 - Choose [Rock/Paper/Scissors] [q - Quit]: ")
    if player2 == 'q':
        break
    if player1 == player2:
        print("Draw")
    elif player1 == 'rock' and player2 == 'paper':
        print("Player 2 Wins!")
    elif player1 == 'rock' and player2 == 'scissors':
        print("Player 1 Wins!")
    elif player1 == 'paper' and player2 == 'rock':
        print("Player 1 Wins!")
    elif player1 == 'paper' and player2 == 'scissors':
        print("Player 2 Wins!")
    elif player1 == 'scissors' and player2 == 'paper':
        print("Player 1 Wins!")
    elif player1 == 'scissors' and player2 == 'rock':
        print("Player 2 Wins!")
    elif player1 not in choices or player2 not in choices:
        print("Not a valid response!")
print("Goodbye!")
