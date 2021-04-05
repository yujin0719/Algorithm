# 4963: 섬의 개수
from collections import deque
dx = [0,0,1,1,1,-1,-1,-1]
dy = [1,-1,0,1,-1,0,1,-1]
while True:
	w, h = map(int,input().split(" "))
	if w == 0 and h == 0 :
		break
	answer = 0
	board = [list(map(int, input().split())) for _ in range(h)]
	q = deque()
	for i in range(h):
		for j in range(w):
			if board[i][j] == 1:
				q.append((i,j))
				board[i][j] = 2
				while q:
					cur = q.popleft()
					for k in range(8):
						nx,ny = cur[0] + dx[k], cur[1] + dy[k]
						if 0 <= nx < h and 0 <= ny < w and board[nx][ny] == 1 :
							q.append((nx,ny))
							board[nx][ny] = 2
				answer += 1
	print(answer)

