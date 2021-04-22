# 1753: 최단 경로
from collections import defaultdict
import heapq
v,e = map(int,input().split(" "))
k = int(input())
inf = 100000000
result = [inf for _ in range(v+1)]
graph = defaultdict(list)
for _ in range(e):
	u, v, w = map(int,input().split(" "))
	graph[u].append([v,w])

heap = []
heapq.heappush(heap,[0,k])
result[k] = 0
while heap:
	dist, node = heapq.heappop(heap)
	if dist != result[node]:
		continue
	for v,w in graph[node]:
		if result[v] > w + dist:
			result[v] = w + dist
			heapq.heappush(heap,[result[v],v])

for dist in result[1:]:
	if dist == inf:
		print("INF")
	else:
		print(dist)


