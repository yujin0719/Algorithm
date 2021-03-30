# 1654: 랜선 자르기
k,n = map(int,input().split())
numbers = []
answer = 0
for _ in range(k):
	numbers.append(int(input()))
left, right = 1, max(numbers)

while left <= right:
	mid = (left + right) // 2
	cnt = 0
	for number in numbers:
		cnt += (number // mid)
	if cnt >= n:
		answer = mid
		left = mid + 1
	else :
		right = mid - 1
	
print(answer)