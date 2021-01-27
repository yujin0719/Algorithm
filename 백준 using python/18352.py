# 18352: 특정거리의 도시찾기
# 이문제 입력받을때 map(int,input().split())히면 시간초과나온다..
ㅣ
from collections import deque
import sys

# n 도시의 개수 / m 도로의 개수 / k 거리정보 / x 출발 도시의 번호
n,m,k,x = map(int,sys.stdin.readline().rstrip().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    temp_x, temp_y = map(int,sys.stdin.readline().rstrip().split())
    graph[temp_x].append(temp_y)

distance = [-1] * (n + 1)
distance[x] = 0

q = deque([x])
while q:
    now = q.popleft()
    for next in graph[now]:
        if distance[next] == -1:
            distance[next] = distance[now] + 1
            q.append(next)

check = False
for i in range(1,n+1):
    if distance[i] == k:
        print(i)
        check = True

if check == False:
    print(-1)
