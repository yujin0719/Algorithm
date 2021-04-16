#1197: 최소 스패닝 트리
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

V,E = map(int,input().split(" "))
edges = []
parent = [x for x in range(V+1)]
for _ in range(E):
	edges.append([*map(int,input().split())])
edges.sort(key = lambda x : x[2])
MST = []
for v,u,w in edges:
	if find(v) != find(u) :
		union(v,u)
		MST.append(w)
print(sum(MST))