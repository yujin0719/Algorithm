#9375: 패션왕 신혜빈
t = int(input())
for _ in range(t):
	n = int(input())
	answer = 1
	wear = {}
	for _ in range(n):
		clothes, kinds = input().split(" ")
		if kinds in wear:
			wear[kinds].append(clothes)
		else :
			wear[kinds] = [clothes]
	for w in wear:
		answer *= (len(wear[w])+1)
	print(answer-1)
