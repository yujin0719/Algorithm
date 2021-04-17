#2579: 계단 오르기
n = int(input())
stall = [0]
for _ in range(n):
	stall.append(int(input()))
DP =[[]*2 for _ in range(n+1)]
DP[0] = [0,0]
if n == 1:
	print(stall[1])
else:
	DP[1] = [stall[1],0]
	DP[2] = [stall[2],stall[1]+stall[2]]
	for i in range(3,n+1):
		DP[i]=[max(DP[i-2][0],DP[i-2][1]) + stall[i], DP[i-1][0] + stall[i]]
	print(max(DP[n][0],DP[n][1]))