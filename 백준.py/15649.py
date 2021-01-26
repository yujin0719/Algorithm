# 15649: n과 m(1)
# backtracking을 사용해 c++과 알고리즘 자체는 매우 유사하지만 python에서만 사용할 수 있는 list의 스택기능과 in 을 사용해 조금 더 간결하게 구현했다. 

n,m = map(int,input().split())
arr = []

def backtracking():
	if len(arr) == m:
		print(" ".join(map(str,arr)))
		return 
	for i in range(1,n+1):
		if i in arr:
			continue
		arr.append(i)
		backtracking()
		arr.pop()

backtracking()
