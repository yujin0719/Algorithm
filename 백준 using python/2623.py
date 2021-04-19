# 2623: 음악프로그램
from collections import deque, defaultdict

n, m = map(int,input().split(" "))
graph = defaultdict(list)
indegree = [0 for _ in range(n+1)]
for _ in range(m):
	tmp = list(map(int,input().split(" ")))
	for i in range(1,len(tmp) -1):
		graph[tmp[i]].append(tmp[i+1])
		indegree[tmp[i+1]] += 1
queue = deque()
for i in range(1,n+1):
	if indegree[i] == 0:
		queue.append(i)
answer = []
while queue:
	cur = queue.popleft()
	answer.append(cur)
	for node in graph[cur]:
		indegree[node] -= 1
		if indegree[node] == 0:
			queue.append(node)
if len(answer) == n:
	for x in answer:
		print(x,sep = " ")
else:
	print(0)
