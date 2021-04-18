#1003: 피보나치 함수
from sys import stdin
t = int(stdin.readline())
D = [[0]*2 for _ in range(41)]
D[0] = [1,0]
D[1] = [0,1]
for i in range(2,41):
	D[i][0] = D[i-1][0] + D[i-2][0]
	D[i][1] = D[i-1][1] + D[i-2][1]
for _ in range(t):
	n = int(stdin.readline())
	print(D[n][0],D[n][1],sep = ' ')


