# Testing string to ascii program
print("Your name in ASCII")
name = input("Enter your name: ")
ascii_name = ""
for character in name:
    if character == ' ':
        pass
    else:
        # Wrote this way for ease of understanding
        ascii_name += character + "{" + str(ord(character)) + "}"
        ascii_name += ' '
print(ascii_name)
