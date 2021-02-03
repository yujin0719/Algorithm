# 1772: 순열의 순서
from math import factorial
a = []
n = int(input())
for i in range(1,n+1):
	a.append(i)
num = list(map(int,input().split()))
if num[0] == 1:
	result = []
	for i in range(n):
		cur = factorial(n-i-1)
		for j in range(1,n+1):
			if num[1] <= cur * j :
				result.append(a[j-1])
				a.pop(j-1)
				num[1] -= cur * (j-1)
				break
	print(" ".join(map(str,result)))
else:
	result = 0
	for i in range(n):
		cur = factorial(n-i-1)
		result += a.index(num[i+1]) * cur
		a.pop(a.index(num[i+1]))
	print(result+1)
	
	
	
	