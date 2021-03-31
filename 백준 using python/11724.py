# 11724: 연결 요소의 개수
n,m = map(int,input().split(" "))
edges = []
for _ in range(m):
	edges.append(list(map(int,input().split(" "))))
check = [0 for _ in range(n)]
stack = [x for x in range(n,0,-1)]
check[0] = 1
while stack:
	cur = stack.pop()
	for edge in edges:
		if edge[0] == cur and check[edge[1]-1] == 0:
			stack.append(edge[1])
			check[edge[1]-1] = check[cur-1] + 1
		if edge[1] == cur and check[edge[0]-1] == 0:
			stack.append(edge[0])
			check[edge[0]-1] = check[cur-1] + 1

print(sum([1 for x in check if x == 0 or x == 1]))

