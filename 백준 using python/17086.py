# 17086: 아기 상어2
from collections import deque

dx = [1,1,1,-1,-1,-1,0,0]
dy = [1,-1,0,1,-1,0,1,-1]

n,m = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]

q = deque()
for i in range(n):
	for j in range(m):
		if board[i][j]:
			q.append((i,j))
			
while q:
	cur = q.popleft()
	for i in range(8):
		nx,ny = cur[0] + dx[i], cur[1] + dy[i]
		if nx >= 0 and nx < n and ny >= 0 and ny < m and not board[nx][ny]:
			q.append((nx,ny))
			board[nx][ny] = board[cur[0]][cur[1]] + 1

print(max(map(max, board))-1)
