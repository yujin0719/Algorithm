#1620: 나는야 포켓몬 마스터 이다솜
#하...백준 Input()은 시간초과 ㅠㅠ

import sys
n,m = map(int, sys.stdin.readline().split(" "))
name,idx = {}, {}
for i in range(n):
	pocketmon = sys.stdin.readline().rstrip()
	name[i+1] = pocketmon
	idx[pocketmon] = i+1
for _ in range(m):
	question = sys.stdin.readline().rstrip()
	if question.isdigit():
		print(name[int(question)])
	else :
		print(idx[question])