import sys


sys.stdin = open("test.txt","r")

a = arr.array(map(int, input().split())).sort()
print(a.count())
# print("Yes" if a.count(a[0]) >= 4 or a.count(a[-1]) >= 4 else "No")