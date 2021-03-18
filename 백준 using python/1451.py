# 1451: 직사각형으로 나누기
n,m = map(int,input().split(" "))
arr = [list(map(int, input())) for _ in range(n)]
answer = 0

def sum(startX,endX,startY,endY):
  result = 0
  for i in range(startX,endX+1):
    for j in range(startY, endY+1):
      result += arr[j][i]
  return result

# 1번모양 
for i in range(0,m-2):
  for j in range(i+1,m-1):
    s1 = sum(0,i,0,n-1)
    s2 = sum(i+1,j,0,n-1)
    s3 = sum(j+1,m-1,0,n-1)
    answer = max(answer,s1*s2*s3)

# 2번모양
for i in range(0,n-2):
  for j in range(i+1,n-1):
    s1 = sum(0,m-1,0,i)
    s2 = sum(0,m-1,i+1,j)
    s3 = sum(0,m-1,j+1,n-1)
    answer = max(answer,s1*s2*s3)

# 3번모양
for i in range(0,m-1):
  for j in range(0,n-1):
    s1 = sum(0,i,0,n-1)
    s2 = sum(i+1,m-1,0,j)
    s3 = sum(i+1,m-1,j+1,n-1)
    answer = max(answer,s1*s2*s3)

# 4번모양
for i in range(0,m-1):
  for j in range(0,n-1):
    s1 = sum(0,i,0,j)
    s2 = sum(0,i,j+1,n-1)
    s3 = sum(i+1,m-1,0,n-1)
    answer = max(answer,s1*s2*s3)

# 5번모양
for i in range(0,n-1):
  for j in range(0,m-1):
    s1 = sum(0,m-1,0,i)
    s2 = sum(0,j,i+1,n-1)
    s3 = sum(j+1,m-1,i+1,n-1)
    answer = max(answer,s1*s2*s3) 

# 6번모양
for i in range(0,n-1):
  for j in range(0,m-1):
    s1 = sum(0,j,0,i)
    s2 = sum(j+1,m-1,0,i)
    s3 = sum(0,m-1,i+1,n-1)
    answer = max(answer,s1*s2*s3)


print(answer)