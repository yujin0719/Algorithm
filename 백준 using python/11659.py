# 11659: 구간 합 구하기
import sys
n, cnt = map(int,sys.stdin.readline().strip().split())
number = list(map(int,sys.stdin.readline().strip().split()))

dp = [0 for _ in range(n+1)]
dp[0] = 0
for i in range(1,n+1):
	dp[i] = dp[i-1] + number[i-1]
for _ in range(cnt):
	i,j = map(int,sys.stdin.readline().strip().split())
	if i != 0:
		print(dp[j]-dp[i-1])
	else :
		print(dp[j])