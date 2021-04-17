# 9095: 1,2,3 더하기
t = int(input())
DP = [0,1,2,4]
for i in range(4,12):
	DP.append(DP[i-1]+DP[i-2]+DP[i-3])
for _ in range(t):
	n = int(input())
	print(DP[n])
