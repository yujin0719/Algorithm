# 10971: 외판원 순회2
# pypy3로 해결...

from itertools import permutations
n = int(input())
weight = []
result = 10000000

for i in range(n):
  weight.append(list(map(int, input().split(" "))))
numbers = permutations([i for i in range(1,n+1)],n)

for number in numbers:
  total,before = 0,0
  for idx,num in enumerate(list(number)):
    if idx == 0:
      before = num-1
      continue
    if weight[before][num-1] == 0:
      break
    else :
      total += weight[before][num-1]
      before = num-1
  
  if before == number[n-1]-1 and weight[before][number[0]-1] != 0:
    result = min(result,total+weight[before][number[0]-1])

print(result)