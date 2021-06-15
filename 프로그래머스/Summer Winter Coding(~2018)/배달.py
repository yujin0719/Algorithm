# 배달
from collections import deque
def solution(N, road, K):
    queue = deque()
    cost = [[0]*N for i in range(N)]
    for x,y,c in road:
        if cost[x-1][y-1] == 0:
            cost[x-1][y-1] = c
            cost[y-1][x-1] = c
        else:
            cost[x-1][y-1] = min(cost[x-1][y-1],c)
            cost[y-1][x-1] = min(cost[y-1][x-1],c)
    for i in range(N):
        if cost[0][i] != 0:
            queue.append(i)
    while queue:
        cur = queue.pop()
        for i in range(1,N):
            if cur != i and cost[cur][i] != 0 and (cost[0][i] == 0 or cost[0][i] > cost[0][cur] + cost[cur][i]):
                queue.append(i)
                cost[0][i] = cost[0][cur] + cost[cur][i]
                
    answer = sum([1 for c in cost[0] if c <= K ])
    return answer