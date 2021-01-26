# 2606: 바이러스
from collections import deque

computer = int(input())
connect = [[0] * computer for _ in range(computer)]
vis = [0 for _ in range(computer)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    connect[x - 1][y - 1] = 1
    connect[y - 1][x - 1] = 1
q = deque()
cnt = 0
q.append(0)
while q:
    cur = q.popleft()
    vis[cur] = 1
    for i in range(computer):
        if connect[cur][i] == 1 and not vis[i]:
            q.append(i)
            vis[i] = 1
            cnt += 1

print(cnt)
