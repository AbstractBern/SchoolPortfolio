#@author: Bernardo Flores - vic398 - 06/05/2019
#bit can be used to put an arbitrary bit #
#program shows hex, binary, and decimal results.
def main():
    bit=32                       #holds number of bits for easier math
    rangeStart=-1*pow(2,bit-1)   #this is for the signed ints
    print("Print least 16 of ", bit, " bits:")
    while (rangeStart < (-1*pow(2, bit-1)) + 16):    #range+16 most least
        print("Hex: %s | Binary: %s | Decimal: %s" % (twosComp(rangeStart,bit),bin(int(twosComp(rangeStart,bit),0)),format(rangeStart,',d')))
        rangeStart+=1
        if (rangeStart>(-1*pow(2,bit-1))+16):
            break
    #while loops for all 258, 8 bit values
    bit=8
    rangeStart=-1*pow(2,bit-1)
    print("Print all values of ", bit," bits:")
    while (rangeStart <= pow(2, bit-1)-1):    #range+16 most least
        if (rangeStart < 0 ):
            print("Hex: %s | Binary: %s | Decimal: %s" % (twosComp(rangeStart,bit),bin(int(twosComp(rangeStart,bit),0)),format(rangeStart,',d')))
        else:
            print("Hex: %s | Binary: %s | Decimal: %s" % (hex(rangeStart),bin(rangeStart),format(rangeStart,',d')))
        rangeStart+=1
        if (rangeStart> pow(2,bit-1)-1):
            break
    print("Print most 16 ", bit, " bits:")
    #loops for most 16 bits of 32 bit
    bit=32
    rangeEnd=(pow(2,bit-1))-16
    while (rangeEnd <= pow(2,bit-1)-1):
        print("Hex: %s | Binary: %s | Decimal: %s" % (hex(rangeEnd),bin(rangeEnd),format(rangeEnd,',d')))
        rangeEnd+=1
        if (rangeEnd > pow(2,bit-1)-1):
            break
    #used for the signed values - :
    #turns decimals into binary to be inverted and added by 1. ret hex values of binary
def twosComp(dec,bit):  #only for when numbers are negative
    newBin=''
    posDec=-1*dec
    #turn decimal to positive to get the unsigned form of the binary to twos complament
    count=0
    preBin='0b'
    value=bin(posDec)
    part=value[2:]
    for x in value[2:]:
        count+=1
    count=bit-count
    preBin+=count*('0')
    preBin+=part    #now this should be a complete positive binary
    #newBin=addBit
    #newBin+=part
    #starts after the "0b" and manipulates
    binary=preBin[:2]
    for x in range(2,len(preBin)):
        if (preBin[x] == "1"):
            newBin+="0"
        elif (preBin[x] == "0"):
            newBin+="1"
    binary+=newBin
    newBin=int(binary, 2)
    #newBin is a binary type
    #add one for twos complament finish
    newBin+=1
    return hex(newBin)
main()
##*********************CONSOLE OUTPUT**********************
##Print least 16 of  32  bits:
##Hex: 0x80000000 | Binary: 0b10000000000000000000000000000000 | Decimal: -2,147,483,648
##Hex: 0x80000001 | Binary: 0b10000000000000000000000000000001 | Decimal: -2,147,483,647
##Hex: 0x80000002 | Binary: 0b10000000000000000000000000000010 | Decimal: -2,147,483,646
##Hex: 0x80000003 | Binary: 0b10000000000000000000000000000011 | Decimal: -2,147,483,645
##Hex: 0x80000004 | Binary: 0b10000000000000000000000000000100 | Decimal: -2,147,483,644
##Hex: 0x80000005 | Binary: 0b10000000000000000000000000000101 | Decimal: -2,147,483,643
##Hex: 0x80000006 | Binary: 0b10000000000000000000000000000110 | Decimal: -2,147,483,642
##Hex: 0x80000007 | Binary: 0b10000000000000000000000000000111 | Decimal: -2,147,483,641
##Hex: 0x80000008 | Binary: 0b10000000000000000000000000001000 | Decimal: -2,147,483,640
##Hex: 0x80000009 | Binary: 0b10000000000000000000000000001001 | Decimal: -2,147,483,639
##Hex: 0x8000000a | Binary: 0b10000000000000000000000000001010 | Decimal: -2,147,483,638
##Hex: 0x8000000b | Binary: 0b10000000000000000000000000001011 | Decimal: -2,147,483,637
##Hex: 0x8000000c | Binary: 0b10000000000000000000000000001100 | Decimal: -2,147,483,636
##Hex: 0x8000000d | Binary: 0b10000000000000000000000000001101 | Decimal: -2,147,483,635
##Hex: 0x8000000e | Binary: 0b10000000000000000000000000001110 | Decimal: -2,147,483,634
##Hex: 0x8000000f | Binary: 0b10000000000000000000000000001111 | Decimal: -2,147,483,633
##Print all values of  8  bits:
##Hex: 0x80 | Binary: 0b10000000 | Decimal: -128
##Hex: 0x81 | Binary: 0b10000001 | Decimal: -127
##Hex: 0x82 | Binary: 0b10000010 | Decimal: -126
##Hex: 0x83 | Binary: 0b10000011 | Decimal: -125
##Hex: 0x84 | Binary: 0b10000100 | Decimal: -124
##Hex: 0x85 | Binary: 0b10000101 | Decimal: -123
##Hex: 0x86 | Binary: 0b10000110 | Decimal: -122
##Hex: 0x87 | Binary: 0b10000111 | Decimal: -121
##Hex: 0x88 | Binary: 0b10001000 | Decimal: -120
##Hex: 0x89 | Binary: 0b10001001 | Decimal: -119
##Hex: 0x8a | Binary: 0b10001010 | Decimal: -118
##Hex: 0x8b | Binary: 0b10001011 | Decimal: -117
##Hex: 0x8c | Binary: 0b10001100 | Decimal: -116
##Hex: 0x8d | Binary: 0b10001101 | Decimal: -115
##Hex: 0x8e | Binary: 0b10001110 | Decimal: -114
##Hex: 0x8f | Binary: 0b10001111 | Decimal: -113
##Hex: 0x90 | Binary: 0b10010000 | Decimal: -112
##Hex: 0x91 | Binary: 0b10010001 | Decimal: -111
##Hex: 0x92 | Binary: 0b10010010 | Decimal: -110
##Hex: 0x93 | Binary: 0b10010011 | Decimal: -109
##Hex: 0x94 | Binary: 0b10010100 | Decimal: -108
##Hex: 0x95 | Binary: 0b10010101 | Decimal: -107
##Hex: 0x96 | Binary: 0b10010110 | Decimal: -106
##Hex: 0x97 | Binary: 0b10010111 | Decimal: -105
##Hex: 0x98 | Binary: 0b10011000 | Decimal: -104
##Hex: 0x99 | Binary: 0b10011001 | Decimal: -103
##Hex: 0x9a | Binary: 0b10011010 | Decimal: -102
##Hex: 0x9b | Binary: 0b10011011 | Decimal: -101
##Hex: 0x9c | Binary: 0b10011100 | Decimal: -100
##Hex: 0x9d | Binary: 0b10011101 | Decimal: -99
##Hex: 0x9e | Binary: 0b10011110 | Decimal: -98
##Hex: 0x9f | Binary: 0b10011111 | Decimal: -97
##Hex: 0xa0 | Binary: 0b10100000 | Decimal: -96
##Hex: 0xa1 | Binary: 0b10100001 | Decimal: -95
##Hex: 0xa2 | Binary: 0b10100010 | Decimal: -94
##Hex: 0xa3 | Binary: 0b10100011 | Decimal: -93
##Hex: 0xa4 | Binary: 0b10100100 | Decimal: -92
##Hex: 0xa5 | Binary: 0b10100101 | Decimal: -91
##Hex: 0xa6 | Binary: 0b10100110 | Decimal: -90
##Hex: 0xa7 | Binary: 0b10100111 | Decimal: -89
##Hex: 0xa8 | Binary: 0b10101000 | Decimal: -88
##Hex: 0xa9 | Binary: 0b10101001 | Decimal: -87
##Hex: 0xaa | Binary: 0b10101010 | Decimal: -86
##Hex: 0xab | Binary: 0b10101011 | Decimal: -85
##Hex: 0xac | Binary: 0b10101100 | Decimal: -84
##Hex: 0xad | Binary: 0b10101101 | Decimal: -83
##Hex: 0xae | Binary: 0b10101110 | Decimal: -82
##Hex: 0xaf | Binary: 0b10101111 | Decimal: -81
##Hex: 0xb0 | Binary: 0b10110000 | Decimal: -80
##Hex: 0xb1 | Binary: 0b10110001 | Decimal: -79
##Hex: 0xb2 | Binary: 0b10110010 | Decimal: -78
##Hex: 0xb3 | Binary: 0b10110011 | Decimal: -77
##Hex: 0xb4 | Binary: 0b10110100 | Decimal: -76
##Hex: 0xb5 | Binary: 0b10110101 | Decimal: -75
##Hex: 0xb6 | Binary: 0b10110110 | Decimal: -74
##Hex: 0xb7 | Binary: 0b10110111 | Decimal: -73
##Hex: 0xb8 | Binary: 0b10111000 | Decimal: -72
##Hex: 0xb9 | Binary: 0b10111001 | Decimal: -71
##Hex: 0xba | Binary: 0b10111010 | Decimal: -70
##Hex: 0xbb | Binary: 0b10111011 | Decimal: -69
##Hex: 0xbc | Binary: 0b10111100 | Decimal: -68
##Hex: 0xbd | Binary: 0b10111101 | Decimal: -67
##Hex: 0xbe | Binary: 0b10111110 | Decimal: -66
##Hex: 0xbf | Binary: 0b10111111 | Decimal: -65
##Hex: 0xc0 | Binary: 0b11000000 | Decimal: -64
##Hex: 0xc1 | Binary: 0b11000001 | Decimal: -63
##Hex: 0xc2 | Binary: 0b11000010 | Decimal: -62
##Hex: 0xc3 | Binary: 0b11000011 | Decimal: -61
##Hex: 0xc4 | Binary: 0b11000100 | Decimal: -60
##Hex: 0xc5 | Binary: 0b11000101 | Decimal: -59
##Hex: 0xc6 | Binary: 0b11000110 | Decimal: -58
##Hex: 0xc7 | Binary: 0b11000111 | Decimal: -57
##Hex: 0xc8 | Binary: 0b11001000 | Decimal: -56
##Hex: 0xc9 | Binary: 0b11001001 | Decimal: -55
##Hex: 0xca | Binary: 0b11001010 | Decimal: -54
##Hex: 0xcb | Binary: 0b11001011 | Decimal: -53
##Hex: 0xcc | Binary: 0b11001100 | Decimal: -52
##Hex: 0xcd | Binary: 0b11001101 | Decimal: -51
##Hex: 0xce | Binary: 0b11001110 | Decimal: -50
##Hex: 0xcf | Binary: 0b11001111 | Decimal: -49
##Hex: 0xd0 | Binary: 0b11010000 | Decimal: -48
##Hex: 0xd1 | Binary: 0b11010001 | Decimal: -47
##Hex: 0xd2 | Binary: 0b11010010 | Decimal: -46
##Hex: 0xd3 | Binary: 0b11010011 | Decimal: -45
##Hex: 0xd4 | Binary: 0b11010100 | Decimal: -44
##Hex: 0xd5 | Binary: 0b11010101 | Decimal: -43
##Hex: 0xd6 | Binary: 0b11010110 | Decimal: -42
##Hex: 0xd7 | Binary: 0b11010111 | Decimal: -41
##Hex: 0xd8 | Binary: 0b11011000 | Decimal: -40
##Hex: 0xd9 | Binary: 0b11011001 | Decimal: -39
##Hex: 0xda | Binary: 0b11011010 | Decimal: -38
##Hex: 0xdb | Binary: 0b11011011 | Decimal: -37
##Hex: 0xdc | Binary: 0b11011100 | Decimal: -36
##Hex: 0xdd | Binary: 0b11011101 | Decimal: -35
##Hex: 0xde | Binary: 0b11011110 | Decimal: -34
##Hex: 0xdf | Binary: 0b11011111 | Decimal: -33
##Hex: 0xe0 | Binary: 0b11100000 | Decimal: -32
##Hex: 0xe1 | Binary: 0b11100001 | Decimal: -31
##Hex: 0xe2 | Binary: 0b11100010 | Decimal: -30
##Hex: 0xe3 | Binary: 0b11100011 | Decimal: -29
##Hex: 0xe4 | Binary: 0b11100100 | Decimal: -28
##Hex: 0xe5 | Binary: 0b11100101 | Decimal: -27
##Hex: 0xe6 | Binary: 0b11100110 | Decimal: -26
##Hex: 0xe7 | Binary: 0b11100111 | Decimal: -25
##Hex: 0xe8 | Binary: 0b11101000 | Decimal: -24
##Hex: 0xe9 | Binary: 0b11101001 | Decimal: -23
##Hex: 0xea | Binary: 0b11101010 | Decimal: -22
##Hex: 0xeb | Binary: 0b11101011 | Decimal: -21
##Hex: 0xec | Binary: 0b11101100 | Decimal: -20
##Hex: 0xed | Binary: 0b11101101 | Decimal: -19
##Hex: 0xee | Binary: 0b11101110 | Decimal: -18
##Hex: 0xef | Binary: 0b11101111 | Decimal: -17
##Hex: 0xf0 | Binary: 0b11110000 | Decimal: -16
##Hex: 0xf1 | Binary: 0b11110001 | Decimal: -15
##Hex: 0xf2 | Binary: 0b11110010 | Decimal: -14
##Hex: 0xf3 | Binary: 0b11110011 | Decimal: -13
##Hex: 0xf4 | Binary: 0b11110100 | Decimal: -12
##Hex: 0xf5 | Binary: 0b11110101 | Decimal: -11
##Hex: 0xf6 | Binary: 0b11110110 | Decimal: -10
##Hex: 0xf7 | Binary: 0b11110111 | Decimal: -9
##Hex: 0xf8 | Binary: 0b11111000 | Decimal: -8
##Hex: 0xf9 | Binary: 0b11111001 | Decimal: -7
##Hex: 0xfa | Binary: 0b11111010 | Decimal: -6
##Hex: 0xfb | Binary: 0b11111011 | Decimal: -5
##Hex: 0xfc | Binary: 0b11111100 | Decimal: -4
##Hex: 0xfd | Binary: 0b11111101 | Decimal: -3
##Hex: 0xfe | Binary: 0b11111110 | Decimal: -2
##Hex: 0xff | Binary: 0b11111111 | Decimal: -1
##Hex: 0x0 | Binary: 0b0 | Decimal: 0
##Hex: 0x1 | Binary: 0b1 | Decimal: 1
##Hex: 0x2 | Binary: 0b10 | Decimal: 2
##Hex: 0x3 | Binary: 0b11 | Decimal: 3
##Hex: 0x4 | Binary: 0b100 | Decimal: 4
##Hex: 0x5 | Binary: 0b101 | Decimal: 5
##Hex: 0x6 | Binary: 0b110 | Decimal: 6
##Hex: 0x7 | Binary: 0b111 | Decimal: 7
##Hex: 0x8 | Binary: 0b1000 | Decimal: 8
##Hex: 0x9 | Binary: 0b1001 | Decimal: 9
##Hex: 0xa | Binary: 0b1010 | Decimal: 10
##Hex: 0xb | Binary: 0b1011 | Decimal: 11
##Hex: 0xc | Binary: 0b1100 | Decimal: 12
##Hex: 0xd | Binary: 0b1101 | Decimal: 13
##Hex: 0xe | Binary: 0b1110 | Decimal: 14
##Hex: 0xf | Binary: 0b1111 | Decimal: 15
##Hex: 0x10 | Binary: 0b10000 | Decimal: 16
##Hex: 0x11 | Binary: 0b10001 | Decimal: 17
##Hex: 0x12 | Binary: 0b10010 | Decimal: 18
##Hex: 0x13 | Binary: 0b10011 | Decimal: 19
##Hex: 0x14 | Binary: 0b10100 | Decimal: 20
##Hex: 0x15 | Binary: 0b10101 | Decimal: 21
##Hex: 0x16 | Binary: 0b10110 | Decimal: 22
##Hex: 0x17 | Binary: 0b10111 | Decimal: 23
##Hex: 0x18 | Binary: 0b11000 | Decimal: 24
##Hex: 0x19 | Binary: 0b11001 | Decimal: 25
##Hex: 0x1a | Binary: 0b11010 | Decimal: 26
##Hex: 0x1b | Binary: 0b11011 | Decimal: 27
##Hex: 0x1c | Binary: 0b11100 | Decimal: 28
##Hex: 0x1d | Binary: 0b11101 | Decimal: 29
##Hex: 0x1e | Binary: 0b11110 | Decimal: 30
##Hex: 0x1f | Binary: 0b11111 | Decimal: 31
##Hex: 0x20 | Binary: 0b100000 | Decimal: 32
##Hex: 0x21 | Binary: 0b100001 | Decimal: 33
##Hex: 0x22 | Binary: 0b100010 | Decimal: 34
##Hex: 0x23 | Binary: 0b100011 | Decimal: 35
##Hex: 0x24 | Binary: 0b100100 | Decimal: 36
##Hex: 0x25 | Binary: 0b100101 | Decimal: 37
##Hex: 0x26 | Binary: 0b100110 | Decimal: 38
##Hex: 0x27 | Binary: 0b100111 | Decimal: 39
##Hex: 0x28 | Binary: 0b101000 | Decimal: 40
##Hex: 0x29 | Binary: 0b101001 | Decimal: 41
##Hex: 0x2a | Binary: 0b101010 | Decimal: 42
##Hex: 0x2b | Binary: 0b101011 | Decimal: 43
##Hex: 0x2c | Binary: 0b101100 | Decimal: 44
##Hex: 0x2d | Binary: 0b101101 | Decimal: 45
##Hex: 0x2e | Binary: 0b101110 | Decimal: 46
##Hex: 0x2f | Binary: 0b101111 | Decimal: 47
##Hex: 0x30 | Binary: 0b110000 | Decimal: 48
##Hex: 0x31 | Binary: 0b110001 | Decimal: 49
##Hex: 0x32 | Binary: 0b110010 | Decimal: 50
##Hex: 0x33 | Binary: 0b110011 | Decimal: 51
##Hex: 0x34 | Binary: 0b110100 | Decimal: 52
##Hex: 0x35 | Binary: 0b110101 | Decimal: 53
##Hex: 0x36 | Binary: 0b110110 | Decimal: 54
##Hex: 0x37 | Binary: 0b110111 | Decimal: 55
##Hex: 0x38 | Binary: 0b111000 | Decimal: 56
##Hex: 0x39 | Binary: 0b111001 | Decimal: 57
##Hex: 0x3a | Binary: 0b111010 | Decimal: 58
##Hex: 0x3b | Binary: 0b111011 | Decimal: 59
##Hex: 0x3c | Binary: 0b111100 | Decimal: 60
##Hex: 0x3d | Binary: 0b111101 | Decimal: 61
##Hex: 0x3e | Binary: 0b111110 | Decimal: 62
##Hex: 0x3f | Binary: 0b111111 | Decimal: 63
##Hex: 0x40 | Binary: 0b1000000 | Decimal: 64
##Hex: 0x41 | Binary: 0b1000001 | Decimal: 65
##Hex: 0x42 | Binary: 0b1000010 | Decimal: 66
##Hex: 0x43 | Binary: 0b1000011 | Decimal: 67
##Hex: 0x44 | Binary: 0b1000100 | Decimal: 68
##Hex: 0x45 | Binary: 0b1000101 | Decimal: 69
##Hex: 0x46 | Binary: 0b1000110 | Decimal: 70
##Hex: 0x47 | Binary: 0b1000111 | Decimal: 71
##Hex: 0x48 | Binary: 0b1001000 | Decimal: 72
##Hex: 0x49 | Binary: 0b1001001 | Decimal: 73
##Hex: 0x4a | Binary: 0b1001010 | Decimal: 74
##Hex: 0x4b | Binary: 0b1001011 | Decimal: 75
##Hex: 0x4c | Binary: 0b1001100 | Decimal: 76
##Hex: 0x4d | Binary: 0b1001101 | Decimal: 77
##Hex: 0x4e | Binary: 0b1001110 | Decimal: 78
##Hex: 0x4f | Binary: 0b1001111 | Decimal: 79
##Hex: 0x50 | Binary: 0b1010000 | Decimal: 80
##Hex: 0x51 | Binary: 0b1010001 | Decimal: 81
##Hex: 0x52 | Binary: 0b1010010 | Decimal: 82
##Hex: 0x53 | Binary: 0b1010011 | Decimal: 83
##Hex: 0x54 | Binary: 0b1010100 | Decimal: 84
##Hex: 0x55 | Binary: 0b1010101 | Decimal: 85
##Hex: 0x56 | Binary: 0b1010110 | Decimal: 86
##Hex: 0x57 | Binary: 0b1010111 | Decimal: 87
##Hex: 0x58 | Binary: 0b1011000 | Decimal: 88
##Hex: 0x59 | Binary: 0b1011001 | Decimal: 89
##Hex: 0x5a | Binary: 0b1011010 | Decimal: 90
##Hex: 0x5b | Binary: 0b1011011 | Decimal: 91
##Hex: 0x5c | Binary: 0b1011100 | Decimal: 92
##Hex: 0x5d | Binary: 0b1011101 | Decimal: 93
##Hex: 0x5e | Binary: 0b1011110 | Decimal: 94
##Hex: 0x5f | Binary: 0b1011111 | Decimal: 95
##Hex: 0x60 | Binary: 0b1100000 | Decimal: 96
##Hex: 0x61 | Binary: 0b1100001 | Decimal: 97
##Hex: 0x62 | Binary: 0b1100010 | Decimal: 98
##Hex: 0x63 | Binary: 0b1100011 | Decimal: 99
##Hex: 0x64 | Binary: 0b1100100 | Decimal: 100
##Hex: 0x65 | Binary: 0b1100101 | Decimal: 101
##Hex: 0x66 | Binary: 0b1100110 | Decimal: 102
##Hex: 0x67 | Binary: 0b1100111 | Decimal: 103
##Hex: 0x68 | Binary: 0b1101000 | Decimal: 104
##Hex: 0x69 | Binary: 0b1101001 | Decimal: 105
##Hex: 0x6a | Binary: 0b1101010 | Decimal: 106
##Hex: 0x6b | Binary: 0b1101011 | Decimal: 107
##Hex: 0x6c | Binary: 0b1101100 | Decimal: 108
##Hex: 0x6d | Binary: 0b1101101 | Decimal: 109
##Hex: 0x6e | Binary: 0b1101110 | Decimal: 110
##Hex: 0x6f | Binary: 0b1101111 | Decimal: 111
##Hex: 0x70 | Binary: 0b1110000 | Decimal: 112
##Hex: 0x71 | Binary: 0b1110001 | Decimal: 113
##Hex: 0x72 | Binary: 0b1110010 | Decimal: 114
##Hex: 0x73 | Binary: 0b1110011 | Decimal: 115
##Hex: 0x74 | Binary: 0b1110100 | Decimal: 116
##Hex: 0x75 | Binary: 0b1110101 | Decimal: 117
##Hex: 0x76 | Binary: 0b1110110 | Decimal: 118
##Hex: 0x77 | Binary: 0b1110111 | Decimal: 119
##Hex: 0x78 | Binary: 0b1111000 | Decimal: 120
##Hex: 0x79 | Binary: 0b1111001 | Decimal: 121
##Hex: 0x7a | Binary: 0b1111010 | Decimal: 122
##Hex: 0x7b | Binary: 0b1111011 | Decimal: 123
##Hex: 0x7c | Binary: 0b1111100 | Decimal: 124
##Hex: 0x7d | Binary: 0b1111101 | Decimal: 125
##Hex: 0x7e | Binary: 0b1111110 | Decimal: 126
##Hex: 0x7f | Binary: 0b1111111 | Decimal: 127
##Print most 16  8  bits:
##Hex: 0x7ffffff0 | Binary: 0b1111111111111111111111111110000 | Decimal: 2,147,483,632
##Hex: 0x7ffffff1 | Binary: 0b1111111111111111111111111110001 | Decimal: 2,147,483,633
##Hex: 0x7ffffff2 | Binary: 0b1111111111111111111111111110010 | Decimal: 2,147,483,634
##Hex: 0x7ffffff3 | Binary: 0b1111111111111111111111111110011 | Decimal: 2,147,483,635
##Hex: 0x7ffffff4 | Binary: 0b1111111111111111111111111110100 | Decimal: 2,147,483,636
##Hex: 0x7ffffff5 | Binary: 0b1111111111111111111111111110101 | Decimal: 2,147,483,637
##Hex: 0x7ffffff6 | Binary: 0b1111111111111111111111111110110 | Decimal: 2,147,483,638
##Hex: 0x7ffffff7 | Binary: 0b1111111111111111111111111110111 | Decimal: 2,147,483,639
##Hex: 0x7ffffff8 | Binary: 0b1111111111111111111111111111000 | Decimal: 2,147,483,640
##Hex: 0x7ffffff9 | Binary: 0b1111111111111111111111111111001 | Decimal: 2,147,483,641
##Hex: 0x7ffffffa | Binary: 0b1111111111111111111111111111010 | Decimal: 2,147,483,642
##Hex: 0x7ffffffb | Binary: 0b1111111111111111111111111111011 | Decimal: 2,147,483,643
##Hex: 0x7ffffffc | Binary: 0b1111111111111111111111111111100 | Decimal: 2,147,483,644
##Hex: 0x7ffffffd | Binary: 0b1111111111111111111111111111101 | Decimal: 2,147,483,645
##Hex: 0x7ffffffe | Binary: 0b1111111111111111111111111111110 | Decimal: 2,147,483,646
##Hex: 0x7fffffff | Binary: 0b1111111111111111111111111111111 | Decimal: 2,147,483,647
