// 1931 : 회의실 배정
n = int(input())
conference = [[int(x) for x in input().split()] for y in range(n)]
conference.sort(key=lambda x: (x[1],x[0]))

result = 0
endTime = 0
for i in range(n):
  if endTime <= conference[i][0]:
    endTime = conference[i][1]
    result += 1

print(result)
