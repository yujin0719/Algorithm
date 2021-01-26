# 15651: n과 m(3) 

n,m = map(int,input().split())
arr = []

def backtracking():
	if len(arr) == m:
		print(" ".join(map(str,arr)))
		return 
	for i in range(1, n+1):
		arr.append(i)
		backtracking()
		arr.pop()
backtracking()
