 # 18405: 경쟁적 전염

from collections import deque
dx = [1,-1,0,0]
dy = [0,0,1,-1]
n,m = map(int,input().split())

board = []
data = []

for i in range(n):
  board.append(list(map(int,input().split())))
  for j in range(n):
    if board[i][j] != 0:
      data.append((board[i][j],0,i,j))
data.sort()
q = deque(data)

s,x,y = map(int,input().split())
while q:
  virus,curs,curx,cury = q.popleft()
  if curs == s:
    break;
  for i in range(4):
    nx = curx + dx[i]
    ny = cury + dy[i]
    if nx >= 0 and nx < n and ny >= 0 and ny < n and board[nx][ny] == 0:
      board[nx][ny] = virus
      q.append((virus,curs+1,nx,ny))

print(board[x-1][y-1])
