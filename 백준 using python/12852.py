# 12852: 1로 만들기 2
n = int(input())
D = [0 for _ in range(n+1)]
pre = [0 for _ in range(n+1)]
for i in range(1,n+1):
	D[i] = D[i-1] + 1
	pre[i] = i-1
	if i % 2 == 0 and D[i] >= D[i//2] + 1:
		D[i] = D[i//2] + 1
		pre[i] = i // 2
	if i % 3 == 0 and D[i] >= D[i//3] + 1:
		D[i] = D[i//3] + 1
		pre[i] = i // 3
print(D[n]-1)
while True:
	if n == 0:
		break
	print(n,end = ' ')
	n = pre[n]
