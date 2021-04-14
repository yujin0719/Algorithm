# 1717: 집합의 표현
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

def find(target):
    if parent[target] != target:
        parent[target] = find(parent[target])
    return parent[target]

def union(a,b):
	a = find(a)
	b = find(b)
	if a < b:
		parent[b] = a
	else :
		parent[a] = b

n,m = map(int,input().split(" "))
parent = [x for x in range(n+1)]
for _ in range(m):
	command,a,b = map(int,input().split(" "))
	if command :
		if find(a) == find(b):
			print("YES")
		else :
			print("NO")
	else:
		union(a,b)