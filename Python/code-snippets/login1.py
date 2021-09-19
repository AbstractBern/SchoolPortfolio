import login
def Start():
    password=input('Enter PassCode: ')
    while not login.valid_password(password):
        print('That password is not valid')
        password=input('Enter passcode ')
    print('This is a Valid Passcode.')
    return password
Start()
