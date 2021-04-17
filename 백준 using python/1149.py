# 1149: RGB거리
n = int(input())
cost = [[0,0,0]]
for _ in range(n):
	cost.append(list(map(int,input().split(" "))))
DP = [[0]*3 for _ in range(n+1)]
DP[1][0],DP[1][1],DP[1][2] = cost[1][0],cost[1][1],cost[1][2]
for i in range(2,n+1):
	DP[i][0] = min(DP[i-1][1],DP[i-1][2]) + cost[i][0]
	DP[i][1] = min(DP[i-1][0],DP[i-1][2]) + cost[i][1]
	DP[i][2] = min(DP[i-1][0],DP[i-1][1]) + cost[i][2]
print(min(DP[n]))