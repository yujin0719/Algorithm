# 16945: 데스 나이트
from collections import deque
dx = [-2,-2,0,0,2,2]
dy = [-1,1,-2,2,-1,1]

n = int(input())
vis = [[0]*n for _ in range(n)]
r1,c1,r2,c2 = map(int,input().split())

q = deque()
q.append((r1,c1))
result = -1
while q:
	cur = q.popleft()
	if cur[0] == r2 and cur[1] == c2:
		result = vis[r2][c2]
		break
	for i in range(6):
		nx,ny = cur[0] + dx[i], cur[1] + dy[i]
		if nx >= 0 and nx < n and ny >= 0 and ny < n and not vis[nx][ny]:
			q.append((nx,ny))
			vis[nx][ny] = vis[cur[0]][cur[1]] + 1
print(result)

