# 11404: 플로이드

n = int(input())
m = int(input())
inf = 100000000
city = [[inf]*(n+1) for _ in range(n+1)]
for _ in range(m):
	a,b,c = map(int,input().split(" "))
	if city[a][b] > c:
		city[a][b] = c
for i in range(1,n+1):
	for j in range(1,n+1):
		for k in range(1,n+1):
			if j != k and city[j][k] > city[j][i] + city[i][k]:
				city[j][k] = city[j][i] + city[i][k]
for i in range(1,n+1):
	for j in range(1,n+1):
		if city[i][j] == inf:
			print(0,end = " ")
		else:
			print(city[i][j],end = " ")
	print()