# level3 네트워크
from collections import deque
def solution(n, computers):
    answer = 0
    vis = [0 for _ in range(n)]
    q = deque()
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1 and vis[i] == 0:
                q.append(i)
                q.append(j)
                vis[i],vis[j] = 1,1 
                answer += 1
                while q:
                    cur = q.pop()
                    for k in range(n):
                        if computers[k][cur] == 1 and vis[k] == 0:
                            q.append(k)
                            vis[k] = 1
    return answer