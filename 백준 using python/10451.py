# 10451: 순열 사이클
from collections import deque
T = int(input())

for _ in range(T):
	n = int(input())
	answer = 0
	number = list(map(int,input().split(" ")))
	check = [0 for _ in range(n)]
	q = deque()
	for i in range(n):
		if check[i] == 0:
			q.append(i)
			answer += 1
			check[i] = 1
			while q:
				cur = q.popleft()
				if check[number[cur]-1] == 0:
					q.append(number[cur]-1)
					check[number[cur]-1] = 1
	print(answer)



