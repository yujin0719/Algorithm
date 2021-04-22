# 11780: 플로이드 2
n = int(input())
m = int(input())
inf = 1000000001
cost = [[inf]*(n+1) for _ in range(n+1)]
nxt = [[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
	a,b,c = map(int,input().split(" "))
	if cost[a][b] > c:
		cost[a][b] = c
		nxt[a][b] = b

for city in range(1,n+1):
	for i in range(1,n+1):
		for j in range(1,n+1):
			if i != j and cost[i][j] > cost[i][city] + cost[city][j]:
				cost[i][j] = cost[i][city] + cost[city][j]
				nxt[i][j] = nxt[i][city]

for i in range(1,n+1):
	for j in range(1,n+1):
		if cost[i][j] == inf:
			print(0,end = ' ')
		else:
			print(cost[i][j],end = ' ')
	print()
for i in range(1,n+1):
	for j in range(1,n+1):
		if i == j:
			print(0)
		else:
			result = []
			start,end = i,j
			while start != end:
				result.append(start)
				start = nxt[start][end]
			result.append(end)
			print(len(result),end = ' ')
			for r in result:
				print(r,end = ' ')
			print()
