# 1449 : 수리공항승

n,L = map(int,input().split())
data = list(map(int,input().split()))
data.sort()

fix = [0] * 1001
cnt = 0

for i in data:
  if fix[i] == 0:
    cnt += 1
    for j in range(i,i+L):
      if j < 1001:
        fix[j] += 1

print(cnt)
