import sys
from os.path import exists
if exists("test.txt"):
	sys.stdin = open("test.txt", "r")

res = 0
for _ in range(int(input())):
    a = list(map(int, input().split()))
    if sum(a) >= 2:
        res += 1
print(res)