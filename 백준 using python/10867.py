# 10867: 중복 빼고 정렬하기

n = int(input())
arr = list(map(int,input().split()))
arr = sorted(list(set(arr)))
for a in arr:
  print (a, end=' ')
