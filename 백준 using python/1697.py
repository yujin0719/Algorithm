# 1697: 숨바꼭질 
from collections import deque

n, k = map(int, input().split(" "))
dp = [-1 for _ in range(100001)]

def dfs(n,k):
  q = deque()
  dp[n] = 0
  q.append(n)
  while q:
    cur = q.popleft()
    if cur == k:
      return dp[k]
    dir = [cur+1,cur-1,cur*2]
    for ndir in dir:
      if ndir >= 0 and ndir <= 100000 and dp[ndir] == -1:
        dp[ndir] = dp[cur] + 1
        q.append(ndir)

print(dfs(n,k))