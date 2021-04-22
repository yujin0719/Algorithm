# 11493: 경로 찾기
n = int(input())
graph = []
for i in range(n):
	graph.append(list(map(int,input().split(" "))))

for city in range(n):
	for i in range(n):
		for j in range(n):
			if graph[i][j] == 0 and graph[i][city] != 0 and graph[city][j] != 0:
				graph[i][j] = 1
for i in range(n):
	for j in range(n):
		print(graph[i][j], end = ' ')
	print()


