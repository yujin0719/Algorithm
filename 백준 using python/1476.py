# 1476 날짜 계산
E,S,M = map(int,input().split(" "))

e,s,m = 1,1,1
day = 1

while E != e or S != s or M!= m:
  e = e+1 if e <= 14 else 1
  s = s+1 if s <= 27 else 1
  m = m+1 if m <= 18 else 1
  day += 1

print(day)
