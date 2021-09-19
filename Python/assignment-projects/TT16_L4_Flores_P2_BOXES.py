#bfd
def main():
    rows = int(input("Enter row amount: "))
    cols = int(input("Enter column amount: "))
    result1 = rows%2
    result2 = cols%2
    if ((result1 and result2) == 0):
        for row in range(rows):
            for col in range(cols):
                print('*', end='')
            print()
    elif ((result1 and result2) != 0):
        for col in range(cols):
            print('*', end='')
        print()
        for col in range(rows-2):
            print('*', ' '*(cols-3)+'*')
        for col in range(cols):
            print('*', end='')
        print()
main()
