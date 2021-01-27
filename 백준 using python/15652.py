# 15652: n과 m(4) 

n,m = map(int,input().split())
arr = []

def backtracking(last):
	if len(arr) == m:
		print(" ".join(map(str,arr)))
		return 
	for i in range(last, n+1):
		arr.append(i)
		backtracking(i)
		arr.pop()
backtracking(1)
