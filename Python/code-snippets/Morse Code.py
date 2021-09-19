# morse code
def main():
    Morse_Table()
def Morse_Table():
    print('\t\t\t\tMorse Code Table')
    print('\t==============================================================')
    list1=['\tSpace\t','space\t','6\t','-....\t','G\t','--.\t','Q\t','--.-']
    cont1 = ' '.join(list1)
    list2=['\tComma\t','--..--\t','7\t','--...\t','H\t','....\t','R\t','.-.']
    cont2 = ' '.join(list2)
    list3=['\tPeriod\t','.-.-.-\t','8\t','---..\t','I\t','..\t','S\t','...']
    cont3 = ' '.join(list3)
    list4=['\t? Mark\t','..--..\t','9\t','----.\t','J\t','.---\t','T\t','-']
    cont4 = ' '.join(list4)
    list5=['\t0\t','-----\t','A\t','.-\t','K\t','-.-\t','U\t','..-']
    cont5 = ' '.join(list5)
    list6=['\t1\t','.---\t','B\t','-...\t','L\t','.-..\t','V\t','...-']
    cont6 = ' '.join(list6)
    list7=['\t2\t','..----\t','C\t','-.-.\t','M\t','--\t','W\t','.--']
    cont7 = ' '.join(list7)
    list8=['\t3\t','...--\t','D\t','-..\t','N\t','-.\t','X\t','-..-']
    cont8 = ' '.join(list8)
    list9=['\t4\t','....-\t','E\t','.\t','O\t','---\t','Y\t','-.-']
    cont9 = ' '.join(list9)
    list10=['\t5\t','.....\t','F\t','..-.\t','P\t','.--.\t','Z\t','--..']
    cont10 = ' '.join(list10)
    print('\tCharacter Code\tCharacter Code\tCharacter Code\tCharacter Code')
    print('\t==============================================================')
    print(cont1,'\n')
    print(cont2,'\n')
    print(cont3,'\n')
    print(cont4,'\n')
    print(cont5,'\n')
    print(cont6,'\n')
    print(cont7,'\n')
    print(cont8,'\n')
    print(cont9,'\n')
    print(cont10,'\n')
    input()
main()
#prints out a table of above
