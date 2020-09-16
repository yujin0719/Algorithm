// 3190 뱀
n = int(input())
k = int(input())

# 오른쪽 아래 왼쪽 위
dx = [0,1,0,-1]
dy = [1,0,-1,0]
command = [] # 회전방향 정보
# 1은 사과가 있는 곳
board = [[0]*n for _ in range(n)]
for _ in range(k):
  r,c = map(int,input().split())
  board[r-1][c-1] = 1

l = int(input())
for _ in range(l):
  a,b = input().split()
  command.append((int(a),b))

def turn(direction, c):
  if c == "L":
    direction = (direction - 1) % 4
  else:
    direction = (direction + 1) % 4
  return direction

def solution():
  x, y = 0,0
  # 머리가 위치하는 곳은 2
  board[x][y] = 2
  # 처음에는 오른쪽을 보고 있음
  direction = 0
  time = 0
  idx = 0
  q = [(x,y)]
  while True:
    nx = x + dx[direction]
    ny = y + dy[direction]
    if nx < 0 or ny < 0 or nx >= n or ny >= n or board[nx][ny] == 2:
      time += 1
      break
    if board[nx][ny] == 0:
      board[nx][ny] = 2
      q.append((nx,ny))
      px,py = q.pop(0)
      board[px][py] = 0
    if board[nx][ny] == 1:
      board[nx][ny] = 2
      q.append((nx,ny))
    x,y = nx, ny
    time += 1
    if idx < l and time == command[idx][0]:
      direction = turn(direction,command[idx][1])
      idx += 1
  return time

print(solution())
