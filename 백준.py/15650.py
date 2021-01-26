# 15650: n과 m(2) 

n,m = map(int,input().split())
arr = []

def backtracking(last):
	if len(arr) == m:
		print(" ".join(map(str,arr)))
		return 
	for i in range(last+1,n+1):
		if i in arr:
			continue
		arr.append(i)
		backtracking(i)
		arr.pop()

backtracking(0)
