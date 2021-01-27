# 1159: 농구 경기

n = int(input())
dic = {}
answer = []
for i in range(n):
    tmp = input()
    if tmp[0] in  dic:
        dic[tmp[0]] += 1
    else:
        dic[tmp[0]] = 1

for d in dic:
    if dic[d] >= 5:
        answer.append(d)

if len(answer) == 0:
    print("PREDAJA")
else:
    answer.sort()
    print("".join(answer))
