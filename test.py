import sys


# sys.stdin = open("test.txt","r")

for _ in range(int(input())):
  # print(_)
  n = int(input())
  a = list(map(int,input().split()))
  b = list(map(int,input().split()))
  suma = 0
  for i in range(len(a)):
    suma += a[i] * (2**i)
  for i in range(len(b)):
    suma -= b[i] * (2**i)
  
  if suma >= 0:
    print("YES")
  else :
    print("NO")