# bernardo flores
# cosc1336, Lab 4 retry, reconsider
# 12/16/2016
# computes austin weather statistics
print('This program computes Austin weather statistics.\nEnter temperatures from -5 to 115.')
total, avg, freezing = 0,0,0
answer = 'y'
temperature = []
while answer.lower() == 'y':
    temp = float(int(input('Enter a temperature: ')))
    while temp not in range(-5,116):
        print('Not valid Temperature Range. Try Again.')
        temp = float(int(input('Enter a temperature: ')))
    if temp <= 32: freezing += 1
    total += temp
    temperature.append(temp)
    counter = len(temperature)
    avg = total/counter
    answer = input('Again = "y", Stop = "qQ" or "quit": ')
    if answer.lower() == 'y': continue
    elif answer in ('qQ' or 'quit'): break
    else: quit()
print('Number of Temps Enter: ', counter)
print('highest temperature: ', max(temperature))
print('Lowest temperature: ', min(temperature))
print('Average temperature: ', avg)
print('Number of Freezing Temps: ', freezing)
#program output
##This program computes Austin weather statistics.
##Enter temperatures -5 to 115.
##Enter a temperature: -10
##Not valid Temperature Range. Try Again.
##Enter a temperature: -5
##Again = "y", Stop = "qQ" or "quit": y
##Enter a temperature: 32
##Again = "y", Stop = "qQ" or "quit": y
##Enter a temperature: 50
##Again = "y", Stop = "qQ" or "quit": y
##Enter a temperature: 100
##Again = "y", Stop = "qQ" or "quit": y
##Enter a temperature: 115
##Again = "y", Stop = "qQ" or "quit": y
##Enter a temperature: 116
##Not valid Temperature Range. Try Again.
##Enter a temperature: 30
##Again = "y", Stop = "qQ" or "quit": q
##Number of Temps Enter:  6
##highest temperature:  115.0
##Lowest temperature:  -5.0
##Average temperature:  53.666666666666664
##Number of Freezing Temps:  3
