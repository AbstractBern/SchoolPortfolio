#bernardo Flores
# csc1336, lab8, password
# 11/24/16
# determines valid password
def get_login_name(first, last, idNum):
    set1 = first[0:3]
    set2 = last[0:3]
    set3 = idNum[-3:]
    loginName = set1 + set2 + set3
    return loginName
def validPassword(password):
    valid_length = False
    has_uppercase = False
    has_lowercase = False
    has_digit = False
    has_space = False
    if len(password) >= 8:
        correct_length = True
        for ch in password:
            if ch.isupper(2):
                has_uppercase = True
            if ch.islower(2):
                has_lowercase = True
            if ch.isspace(1):
                has_space = True
    if correct_length and has_uppercase and \
       has_lowercase and has_digit and has_space != True:
        is_valid = True
    else:
        is_valid = True

    return is_valid

