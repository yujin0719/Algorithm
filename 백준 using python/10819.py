# 10819: 차이를 최대로
n = int(input())
arr = list(map(int,input().split(" ")))
result = 0

left,right = max(arr),min(arr)
arr.remove(left)
arr.remove(right)
result += left-right

while arr:
  l = list(map(lambda x:abs(x-left), arr))
  r = list(map(lambda x:abs(x-right), arr))
  maxL,maxR = max(l),max(r)
  if(maxL >= maxR):
    result +=  maxL
    left = arr[l.index(maxL)]
    arr.remove(arr[l.index(maxL)])
  else:
    result +=  maxR
    right = arr[r.index(maxR)]
    arr.remove(arr[r.index(maxR)])

print(result)