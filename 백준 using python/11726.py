# 11726: 2Xn 타일링
n = int(input())
DP = [0,1,2]
if n > 2:
	for i in range(3,n+1):
		DP.append((DP[i-1] + DP[i-2]) % 10007)
print(DP[n])