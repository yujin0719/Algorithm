# 게임 맵 최단거리
from collections import deque
dx = [1,-1,0,0]
dy = [0,0,1,-1]
def solution(maps):
    answer = 0
    n, m = len(maps), len(maps[0])
    queue = deque()
    queue.append(([0,0]))
    maps[0][0] = 2
    while queue:
        cur = queue.popleft()
        for i in range(4):
            nx,ny = cur[0] + dx[i] , cur[1] + dy[i]
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                maps[nx][ny] = maps[cur[0]][cur[1]] + 1
                queue.append([nx,ny])
    return maps[n-1][m-1] -1 if maps[n-1][m-1] > 1 else -1