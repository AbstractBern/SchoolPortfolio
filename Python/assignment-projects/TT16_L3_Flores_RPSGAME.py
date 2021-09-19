# Bernardo Flores
# COSC1336, Lab 3, Part 3
# September 25, 2016
# This program determines the winner of a Rock-Paper-Scissors Game
# through decision structures.
print("Game of Rock, Paper, Scissors.")
# let the games begin.des
player1 = input("Player 1: Choose one (rock/paper/scissors): ")
player2 = input("Player 2: Choose one (rock/paper/scissors): ")
if (player1 == player2):
    print("Draw.")
elif (player1 == 'rock'):
        if(player2 == 'paper'):
            print("Player2 Wins!")
        else:
            print("Player1 Wins!")
elif (player1 == 'paper'):
        if(player2 == 'rock'):
            print("Player1 Wins!")
        else:
            print("Player2 Wins!")
elif (player1 == 'rock'):
        if (player2 == 'scissors'):
            print("Player1 Wins!")
        else:
            print("Player2 Wins!")
elif (player1 == 'scissors'):
        if (player2 == 'rock'):
            print("Player2 Wins!")
        else:
            print("Player1 Wins!")
elif (player1 == 'paper'):
        if (player2 == 'scissors'):
            print("Player2 Wins!")
elif (player1 == 'scissors'):
        if (player2 == 'paper'):
            print("Player1 Wins!")
player1 = input("Player 1: Choose one (rock/paper/scissors): ")
player2 = input("Player 2: Choose one (rock/paper/scissors): ")
if (player1 == player2):
    print("Draw.")
elif (player1 == 'rock'):
        if(player2 == 'paper'):
            print("Player2 Wins!")
        else:
            print("Player1 Wins!")
elif (player1 == 'paper'):
        if(player2 == 'rock'):
            print("Player1 Wins!")
        else:
            print("Player2 Wins!")
elif (player1 == 'rock'):
        if (player2 == 'scissors'):
            print("Player1 Wins!")
        else:
            print("Player2 Wins!")
elif (player1 == 'scissors'):
        if (player2 == 'rock'):
            print("Player2 Wins!")
        else:
            print("Player1 Wins!")
elif (player1 == 'paper'):
        if (player2 == 'scissors'):
            print("Player2 Wins!")
elif (player1 == 'scissors'):
        if (player2 == 'paper'):
            print("Player1 Wins!")

var = input('press any key to close ')
# Program Output:
##I want to play a game.
##Player 1: Choose one (rock/paper/scissors): rock
##Player 2: Choose one (rock/paper/scissors): rock
##Draw.
##Player 1: Choose one (rock/paper/scissors): paper
##Player 2: Choose one (rock/paper/scissors): paper
##Draw.
# Restart
##I want to play a game.
##Player 1: Choose one (rock/paper/scissors): scissors
##Player 2: Choose one (rock/paper/scissors): scissors
##Draw.
##Player 1: Choose one (rock/paper/scissors): rock
##Player 2: Choose one (rock/paper/scissors): paper
##Player2 Wins!
## Restart
##I want to play a game.
##Player 1: Choose one (rock/paper/scissors): paper
##Player 2: Choose one (rock/paper/scissors): rock
##Player1 Wins!
##Player 1: Choose one (rock/paper/scissors): rock
##Player 2: Choose one (rock/paper/scissors): scissors
##Player1 Wins!
# Restart
##I want to play a game.
##Player 1: Choose one (rock/paper/scissors): scissors
##Player 2: Choose one (rock/paper/scissors): rock
##Player2 Wins!
##Player 1: Choose one (rock/paper/scissors): paper
##Player 2: Choose one (rock/paper/scissors): scissors
##Player2 Wins!
# Restart
##I want to play a game.
##Player 1: Choose one (rock/paper/scissors): scissors
##Player 2: Choose one (rock/paper/scissors): paper
##Player1 Wins!
##Player 1: Choose one (rock/paper/scissors): rock
##Player 2: Choose one (rock/paper/scissors): scissors
##Player1 Wins!
