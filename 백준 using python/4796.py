# 4796 : 캠핑
cnt = 0
while True:
  L,P,V = map(int,input().split())
  cnt += 1
  if L == 0 and P == 0 and V == 0:
    break
  day = (V//P)*L
  if V-(V//P)*P > L:
    day += L
  else:
    day += V - (V//P)*P
  print("Case "+str(cnt)+": "+str(day))
