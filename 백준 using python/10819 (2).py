# 10819: 차이를 최대로
from itertools import permutations
n = int(input())
arr = list(map(int,input().split(" ")))
result = 0

numbers = permutations(arr,n)

for number in numbers:
  before,total = 0,0
  for idx, num in enumerate(list(number)):
    if idx == 0:
      before = num
      continue
    total += abs(before-num)
    before = num
  result = max(result,total)

print(result)
