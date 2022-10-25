import sys
from os.path import exists
if exists("test.txt"):
	sys.stdin = open("test.txt", "r")

for _ in range(int(input())):
	n = int(input())
	


