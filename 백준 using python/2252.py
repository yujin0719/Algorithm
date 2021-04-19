# 2252: 줄 세우기
import collections
from collections import deque

n,m = map(int,input().split(" "))
indegree = [0 for _ in range(n+1)]

queue = deque()
graph = collections.defaultdict(list)

for _ in range(m):
	a,b = map(int,input().split(" "))
	graph[a].append(b)
	indegree[b] += 1

for i in range(1,n+1):
	if indegree[i] == 0:
		queue.append(i)

result = []
while queue:
	cur = queue.popleft()
	result.append(cur)
	for node in graph[cur]:
		indegree[node] -= 1
		if indegree[node] == 0:
			queue.append(node)


for student in result:
	print(student,end = " ")