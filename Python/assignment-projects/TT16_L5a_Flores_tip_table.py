# Name: Bernardo Flores
# COSC1336, Lab 5a, part 2: Use a tip function to create a tip table
# October 15, 2016
# Tip table function

def display_total_due(bill_with_tax, tip_rate, tax_rate):
    tax_rate = 0.0825
    bill_without_tax = bill_with_tax / (1 + tax_rate)
    tip = bill_without_tax * tip_rate
    total_due = bill_with_tax + tip
    print("Total due with ", tip_rate, "% tip: ", format(total_due, '.2f'))

# Add a main function here
def main():
    bill_with_tax = float(input('enter the bill with tax: '))
    tax_rate = 0.0825
    display_total_due(bill_with_tax, 0.10, tax_rate)
    display_total_due(bill_with_tax, 0.15, tax_rate)
    display_total_due(bill_with_tax, 0.20, tax_rate)
    display_total_due(bill_with_tax, 0.25, tax_rate)
    
main()

# Program output:
##your bill with tax is bill_without_tax * tax_rate
##enter the bill with tax: 10.82
##Total due with 0.1 %: 12.79
##enter the bill with tax: 10.82
##Total due with 0.15 %: 13.34
##enter the bill with tax: 10.82
##Total due with 0.2 %: 13.88
##enter the bill with tax: 10.82
##Total due with 0.25 %: 14.42
