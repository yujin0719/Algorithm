# 네트워크
from collections import deque
def solution(n, computers):
    answer = 0
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1:
                q = deque()
                q.append((i,j))
                answer += 1
                while q:
                    x,y = q.popleft()
                    computers[x][y] = 2
                    computers[y][x] = 2
                    for k in range(n):
                        if computers[x][k] == 1:
                            q.append((x,k))
                            q.append((k,x))
    return answer