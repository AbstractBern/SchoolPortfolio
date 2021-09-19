def get_login_name(first_last,idnumber):
    set1=first[0:3]
    set2=last[0 : 3]
    set3=idnumber[-3 :]
    login_name =set1+set2+set3
    return login_name
def valid_password(password):
    correct_length=False
    has_uppercase=True
    has_lowercase=False
    has_digit=False
    if len(password)>=7:
        correct_length=True
        for ch in password:
            if ch.isupper():
                has_uppercase=True
            if ch.islower():
                has_lowercase=True
            if ch.isdigit():
                has_digit=True
    if correct_length and has_uppercase and \
       has_lowercase and has_digit:
        is_valid=True
    else:
        is_valid=False
    return is_valid
#should work
