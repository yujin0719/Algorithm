# 2644: 촌수계산
from collections import deque

n = int(input())
result = -1
man = list(map(int, input().split()))
relation = [[0] * (n + 1) for _ in range(n + 1)]
check = [0 for _ in range(n + 1)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    relation[x][y] = 1
    relation[y][x] = 1

q = deque()
q.append(man[0])
check[man[0]] = 1
while q:
    cur = q.popleft()
    if cur == man[1]:
        result = check[cur] - 1
        break
    for i in range(n + 1):
        if relation[cur][i] == 1 and not check[i]:
            q.append(i)
            check[i] = check[cur] + 1
print(result)
