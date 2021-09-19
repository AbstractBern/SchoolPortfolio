import login
def main():
    password = input('Enter your password: ')
    while not login.validPassword(password):
        print('That password is not valid.')
        password = input('Enter a valid password.')
    print('That is a valid password.')
main()
