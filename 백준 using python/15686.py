// 15686: 치킨 배달
from itertools import combinations

n,m = map(int,input().split())

check = [[0]*n for _ in range(n)]
house, chicken = [],[]
for i in range(n):
  data = list(map(int, input().split()))
  for j in range(n):
    if data[j] == 1:
      house.append((i,j))
    elif data[j] == 2:
      chicken.append((i,j))

combination = list(combinations(chicken,m))

def dist_sum(combination):
  result = 0
  for x, y in house:
    temp = 1e9
    for nx, ny in combination:
      temp = min(temp,abs(x-nx)+abs(y-ny))
    result += temp
  return result

result = 1e9
for c in combination:
  result = min(result, dist_sum(c))

print(result)
