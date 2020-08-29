from time import sleep
from random import randint

digits = [0,1,2,3]


def incDigits(n):
    if digits[n] >= 9 :
        digits[n] = 0
    else:
        digits[n] += 1     

def testDigits():
    total = 0
    total += 1000 * digits[0]
    total += 100 * digits[1]
    total += 10 * digits[2]
    total += digits[3]
    if total % 9 == 0:
        #goodNoise()
        print("Unlocked!!!!!!")
    else:
        #badNoise()
        print("BZZZZZZZTTTTTT")

def randomDigits():
    for n in range(0,4):
        digits[n] = randint(0,9)
        
#testloop - 1-6 for gates, 'q' to quit. End chute happens a few seconds after all 6 gates passed
while 1:

	testInput = input()
	if testInput == 1:
		incDigits(0)
	elif testInput == 2:
		incDigits(1)
	elif testInput == 3:
		incDigits(2)
	elif testInput == 4:
		incDigits(3)
	elif testInput == 5:
		testDigits()
	elif testInput == 6:
		randomDigits()
	elif testInput == 0:
		quit()
		
	print(digits)

	sleep(.01)

