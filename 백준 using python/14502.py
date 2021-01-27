# 14502: 연구소
# 파이썬은 시간초과가 나와서 pypy로 했음
n,m = map(int,input().split())
board = []
tmp = [[0] * m for _ in range(n)]

for _ in range(n):
  board.append(list(map(int,input().split())))

dx = [-1,0,1,0]
dy = [0,1,0,-1]

def spread(x,y):
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx >= 0 and nx < n and ny >= 0 and ny < m:
      if tmp[nx][ny] == 0:
        tmp[nx][ny] = 2
        spread(nx,ny)

def safe_area():
  area = 0
  for i in range(n):
    for j in range(m):
      if tmp[i][j] == 0:
        area += 1
  return area

result = 0
def select(cnt):
  global result
  if cnt == 3:
    for i in range(n):
      for j in range(m):
        tmp[i][j]= board[i][j]
    for i in range(n):
      for j in range(m):
        if tmp[i][j] == 2:
          spread(i,j)
    result = max(result, safe_area())
    return

  for i in range(n):
    for j in range(m):
      if board[i][j] == 0:
        board[i][j] = 1
        cnt += 1
        select(cnt)
        board[i][j] = 0
        cnt -= 1

select(0)
print(result)
