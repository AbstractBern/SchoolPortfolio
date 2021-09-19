#Bernardo Flores
#stock sale revised but not sure how this is suppose to work or
#how stock gain or loss works

def main():
    print ("This program computes the result of a stock transaction.")
    start_balance = float(input("Enter your starting balance: "))
    user_choice = "Yes"
    while (user_choice != "No"):
        stock_name = input("What is the name of the chosen stock? ")
        purchased_shares = float(input("Enter purchased shared: "))
        stock_bought = float(input("Enter amount paid for stock per share: "))
        commission = (purchased_shares*stock_bought)
        print(format(commission, ',f')); print("is deducted from your balance.")
        start_balance-=commission
        print("Balance is ", (format(start_balance, ',f')))
        user_choice = input("\nWould you like to try agan (Yes/No) ? ")
    print("Goodbye.")
main()
##needs better format specifier when  as in print
##ex: 20.00 <--- it print outs .00000
