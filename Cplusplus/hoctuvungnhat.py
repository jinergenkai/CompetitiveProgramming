import sys
from os.path import exists
import random
import os


cnt = ""
a = []
count = 0
for _ in open("test.txt", "r", encoding='utf-8'):
	if _.strip() == "":
		continue
	if cnt != "":

		# a.append([cnt.strip(),_.strip()])
		cnt = cnt.strip().replace('（', '(').replace('）',')').replace(')',' ')
		a.append([cnt.strip().split('(')[-1],_.strip()])

		count += 1
		cnt = ""
	else:
		cnt = _


clear = lambda: os.system('cls')

print(count)
clear()


ran = -1
while True:	
	# ran = random.randint(0,count-1)
	ran = (ran + 1) % count

	print(a[ran][0],end="")
	test = input()
	clear()
	print(a[ran][0] + '\n' + a[ran][1],end="\n_______________\n\n")