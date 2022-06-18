import sys
import os
# @param: 2d array (3x3)
# Tests whether the array is a magic square (paths add to 15)
magicTable = eval(sys.argv[1])
def lo_shu_magic_square(magic_table):
    size = len(magic_table)
    rowSum = 0
    colSum = 0
    diag = 0
    downDiagSum = 0
    diagError = downError = rowError = columnsError = False
    
    print("LO-SHU MAGIC TABLE")
    for y in magic_table:
        for x in y:
            print(str(x), end=" ")
        print('')
    # this loop sums separately the rows and columns
    for y in range(0, size):
        for x in range(0,len(magic_table[y])):
            rowSum += magic_table[y][x]
            colSum += magic_table[x][y]
        if colSum != 15 and rowSum != 15:
            columnsError = True
            rowError = True
        colSum = 0
        rowSum = 0
    # this loop sums up separately the diagnals from each two corners
    for y in range(0,size):
        diag += magic_table[y][size-1-y]
        downDiagSum += magic_table[y][y]
    if downDiagSum != 15 or diag != 15:
        downError = True
        diagError = True
    # Results
    if diagError and downError and rowError and columnsError:
        return 0
    else:
        return 1

ret = lo_shu_magic_square(magicTable)
if ret:
    print("DOES MEET LO-SHU MAGIC PROPERTY.")
else:
    print("DOES NOT MEET LO-SHU MAGIC PROPERTY.")
