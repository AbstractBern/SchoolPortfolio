# bernardo flores
# cosc1336
# 12/15/2016
# pogram that spell-checks and provies a word count.
# good except and no ask the user for the dictionary
word='dictionary.txt'
dict_file = open(word, 'r')
line=dict_file.readline()
dictionary = []
for line in dict_file:
    word=line.rstrip('\n')
    dictionary.append(word)
dict_file.close()
def main():
    function()
    load_dictionary()
    spellcheck()
def function():
    print("This is a Spell checking program.")
def load_dictionary():
    word='dictionary.txt'
    dict_file = open(word, 'r')
    if word.endswith('.txt'):
        print('Valid File...Continuing')
    else:
        print('FILE DOES NOT CONTAIN ".TXT"; NOW ADDING .TXT')
        word+='.txt'
    try:
        dict_file = open(word, 'r')
        count = 0
        content = []
        for line in dict_file:
            count+=1
        print(count, 'Amount of Words in Dictionary..')
        dict_file.close()
    except IOError:
        print('AN ERROR OCCURED WHILE TRYING TO READ THE FILE ', word)
def spellcheck():
    try:
        user = input('Enter a file to spell check; enter nothing to quit: ')
        if user.endswith('.txt'):
            print('Valid File...Continuing')
        elif '.txt' not in user:
            print('FILE DOES NOT CONTAIN ".TXT"; NOW ADDING .TXT')
            user+='.txt'
        elif user.isspace():
            print('Goodbye')
            quit()
        file = open(user,'r')
        end_of_file = False
        number_line = 0
        line = file.readline()
        while not end_of_file:
            number_line+=1
            print('Line',number_line,':')
            content = line.rstrip('\n')
            words=content.split()
            if words not in dictionary:
                print(word,'on',number_line,'not found')
        file.close()
    except FileNotFoundError:
        print('File Not Found.')
    except EOFError:
        end_of_file=True
main()
#enhance for mispelled words, check valid alpha and punctuation del.
#change upper to lower
