lsit1 = ['a', 'b', 'c']
tuple1 = ('a', 'b', 'c')
set1 = {'a', 'b', 'c'}
def apply(in_list, function):
    new_list=[]
    for item in in_list:
        new_list+=(function(item))
    return new_list

letter_ords = list(range(ord('a'), ord('z')+1))
letter_chrs = apply(letter_ords, chr)
print(letter_chrs)
#sets are mutable with len and add and cant be sliced or index
#pair(n:x)
#results in dictionary
# can index 'a' and get its right hand side: inex {a} and get 'object'
