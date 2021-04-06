#10026: 적록색약

from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n = int(input())
board = [[x for x in input()] for _ in range(n)]
check = [[0]*n for _ in range(n)]
answer = [0,0]
for i in range(n):
	for j in range(n):
		if check[i][j] == 0:
			q = deque()
			answer[0] += 1
			check[i][j] = 1
			q.append((i,j))
			color = board[i][j]
			while q:
				cur = q.popleft()
				for k in range(4):
					nx = cur[0] + dx[k]
					ny = cur[1] + dy[k]
					if 0 <= nx < n and 0 <= ny < n and check[nx][ny] == 0 and board[nx][ny] == color:
						q.append((nx,ny))
						check[nx][ny] = 1
                        
for i in range(n):
	for j in range(n):
		if check[i][j] != 2:
			q = deque()
			answer[1] += 1
			check[i][j] = 2
			q.append((i,j))
			if board[i][j] == 'G' or board[i][j] == 'R':
				color = ['R','G']
			else:
				color = ['B']
			while q:
				cur = q.popleft()
				for k in range(4):
					nx = cur[0] + dx[k]
					ny = cur[1] + dy[k]
					if 0 <= nx < n and 0 <= ny < n and check[nx][ny] != 2 and board[nx][ny] in color:
						q.append((nx,ny))
						check[nx][ny] = 2
print(answer[0],answer[1],sep = " ")
								