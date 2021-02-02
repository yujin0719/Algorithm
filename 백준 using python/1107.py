# 1107 리모컨
n = int(input())
brokenNum = int(input())
if brokenNum != 0:
	broken = list(map(int, input().split()))
else : 
	broken = []
result = abs(n-100)
for number in range(n,1000001):
	for num in str(number):
		if int(num) in broken:
			break
	else :
		result = min(result,abs(n-number)+len(str(number)))
		break

for number in range(n,-1,-1):
	for num in str(number):
		if int(num) in broken:
			break
	else :
		result = min(result,abs(n-number)+len(str(number)))
		break

print(result)