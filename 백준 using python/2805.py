# 2805: 나무 자르기
n,m = map(int,input().split(" "))
trees = list(map(int,input().split(" ")))
left,right = 1, max(trees)
answer = 0
while left <= right:
	mid = (left + right) // 2
	leng = 0
	for tree in trees:
		leng += (tree-mid if tree - mid > 0 else 0)
	if leng >= m:
		answer = mid
		left = mid + 1
	else :
		right = mid - 1
print(answer)