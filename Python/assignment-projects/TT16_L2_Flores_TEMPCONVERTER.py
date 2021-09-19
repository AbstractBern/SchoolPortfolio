#Bernardo Flores
#Temp Converter
def main():
    print("This program performs temperature conversion from " + \
          "celcis to Fahrenheit.")
    question_response=input("Would you like to convert? (Yes/No): ")
    response = question_response
    while (response != "No"):
        num=int(input("Enter a number to convert: "))
        fahrenheit = num*(9/5) + 32
        print(fahrenheit, "in Fahrenheit.")
        response = input("Would you like to convert again? ")
    print("GoodBye")
main()
    
