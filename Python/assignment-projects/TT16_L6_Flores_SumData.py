# Bernardo FLores
# COSC1336, Lab 6 Sumdata
# 11/16/2016
#collab with Michael
# Calculate files of data into sums
def main():
    print("This program adds up a list of numbers in a file.")
    while True:
        total = 0.0
        line_count = 0
        name_of_file = input("Enter file name without '.txt' or (Enter to quit): ")
        if name_of_file == "":
            print("Exiting")
            exit()
        name_of_file = name_of_file.lower() + ".txt"
        try:
            infile = open(name_of_file, "r")
            for line in infile:
                line_count += 1
                amount = float(line)
                total += amount
            infile.close()
            print(format(total, ",.2f"))
        except ValueError:
            print("Non-numeric data found in file", name_of_file, "at line", line_count, "with input:", line.rstrip("\n"))
        except IOError:
            print("A read error occurred on file:", name_of_file)
        except Exception as err:
            print(err)
            print("Please reference Python.org for additional help. ")
main()
#program output
##This program adds up a list of numbers in a file.
##Enter file name without '.txt' or (Enter to quit): sales_data
##169,187.71
##Enter file name without '.txt' or (Enter to quit): data1
##6,600.66
##Enter file name without '.txt' or (Enter to quit): data2
##Non-numeric data found in file data2.txt at line 3 with input: three hundred
##Enter file name without '.txt' or (Enter to quit): 
##Exiting
