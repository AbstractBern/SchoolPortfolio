# bernard flores
# cosc1336, lab 9 pickle secret file
# 12/7/2016
# load file, pickle and read
import pickle
def main():
    end_of_file = False
    data_file = open('secret.dat', 'rb')
    while not end_of_file:
        try:
            targ = pickle.load(data_file)
            print(targ)
        except EOFError:
               end_of_file = True
    data_file.close()
main()

#program output:
##The mists of time run thick and thin.
##{1: 'George', 'Foreman': (5, 'George'), 41: 'George', 43: 'George', 'by': ['G', 'e', 'o', 'r', 'g', 'e'], 'George': 'name'}
##[[[[[['deep'], 'in'], 'the'], 'heart'], 'of'], 'Texas']
##{True, 3, 'hash-me', ('zip', 'code'), 'egg', (90210, 20500, 10001), 123.456}
##5
