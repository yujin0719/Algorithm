# 2979: 트럭 주차

a,b,c = map(int,input().split(" "))
answer = 0
time_List = []
for i in range(3):
  start,end = map(int ,input().split(' '))
  time_List.append([start,end])
time_List.sort(key = lambda x : x[1], reverse = True)
for i in range(1,time_List[0][1]+1):
  tmp = 0
  for j in range(3):
    if time_List[j][0] <= i < time_List[j][1]:
      tmp += 1
  if tmp == 1:
    answer += a
  elif tmp == 2:
    answer += b*2
  elif tmp == 3:
    answer += c*3
print(answer)
