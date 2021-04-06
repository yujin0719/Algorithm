# 6593: 상범빌딩
from collections import deque
dx = [0,0,0,0,1,-1]
dy = [0,0,1,-1,0,0]
dz = [1,-1,0,0,0,0]

while True:
	L,R,C = map(int,input().split(" "))
	if L == 0 and R == 0 and C == 0:
		break
	building = [[[]*C for _ in range(R)] for _ in range(L)]
	check = [[[-1]*C for _ in range(R)] for _ in range(L)]
	flag = False
	q = deque()
	for i in range(L):
		for j in range(R):
			building[i][j] = list(input())
			if 'S' in building[i][j]:
				q.append((i,j,building[i][j].index('S')))
				check[i][j][building[i][j].index('S')] = 0
		input()
	while q:
		cur = q.popleft()
		if building[cur[0]][cur[1]][cur[2]] == 'E':
			print("Escaped in {0} minute(s).".format(check[cur[0]][cur[1]][cur[2]]))
			flag = True
			break
		for i in range(6):
			nz,ny,nx = cur[0]+dz[i],cur[1]+dy[i],cur[2]+dx[i]
			if 0 <= nx < C and 0 <= ny < R and 0 <= nz < L and building[nz][ny][nx] != '#' and check[nz][ny][nx] == -1:
				q.append((nz,ny,nx))
				check[nz][ny][nx] = check[cur[0]][cur[1]][cur[2]] + 1
	if not flag:
		print("Trapped!")