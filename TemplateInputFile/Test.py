import sys
from os.path import exists
if exists("test.txt"):
	sys.stdin = open("test.txt", "r")

res = 2
print(res)