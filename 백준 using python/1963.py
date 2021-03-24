# 1963: 소수 경로
import math
from collections import deque

t = int(input())
prime = [1 for _ in range(10001)]
for i in range(2, int(math.sqrt(10001))+1):
	if prime[i] == 1:
		j = 2
		while i * j <= 10000:
			prime[i*j] = 0
			j += 1

for _ in range(t):
	n1, n2 = map(int,input().split())
	number = [-1 for _ in range(10001)]
	def bfs():
		queue = deque()
		queue.append(n1)
		number[n1] = 0
		while queue:
			cur = queue.popleft()
			if cur == n2:
				return number[cur]
			for i in range(4):
				for j in range(10):
					if i == 0 and j == 0:
						continue
					tmp = int(str(cur)[:i] + str(j) + str(cur)[i+1:])
					if prime[tmp] and number[tmp] == -1:
						number[tmp] = number[cur]+1
						queue.append(tmp)
		return -1
	answer = bfs()
	if answer == -1:
		print("impossible")
	else:
		print(answer)
