# 1389: 케빈 베이컨의 6단계 법칙
from collections import deque
n,m = map(int,input().split(" "))
relation = [[0]*n for _ in range(n)]
for i in range(m):
	a,b = map(int,input().split(" "))
	relation[a-1][b-1] = 1
	relation[b-1][a-1] = 1

for i in range(n):
	q = deque()
	for j in range(n):
		if relation[i][j] == 1:
			q.append(j)
	while q:
		cur = q.popleft();
		for k in range(n):
			if k != i and relation[cur][k] == 1 and relation[i][k] == 0:
				q.append(k)
				relation[i][k] = relation[i][cur] + 1
				
result = [sum(x) for x in relation]
print(result.index(min(result))+1)
		