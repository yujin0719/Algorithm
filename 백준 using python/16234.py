# 16234: 인구이동
from collections import deque
n,l,r = map(int,input().split())
world = [list(map(int,input().split())) for _ in range(n)]
result = 0
dx = [0,0,1,-1]
dy = [1,-1,0,0]

while True: 
	vis = [[0]*n for _ in range(n)]
	cnt = 0
	union = {}
	for i in range(n):
		for j in range(n):
			if not vis[i][j]:
				cnt += 1
				q = deque()
				q.append([i,j])
				vis[i][j] = cnt
				total = world[i][j]
				numOfunion = 1
				while q:
					x,y = q.popleft()
					for k in range(4):
						nx,ny = x + dx[k],y + dy[k]
						if 0 <= nx < n and 0 <= ny < n and not vis[nx][ny] and l <= abs(world[nx][ny]-world[x][y]) <= r:
							total += world[nx][ny]
							vis[nx][ny] = cnt
							numOfunion += 1
							q.append([nx,ny])
				union[cnt] = [total,numOfunion]
					
		# 국경선이 열리지 않는 경우 => 차이가 발생하지 않은 경우 
	if cnt == n*n:
		break
	result += 1
	for i in range(n):
		for j in range(n):
			world[i][j] = union[vis[i][j]][0] // union[vis[i][j]][1]
print(result) ㄴ구