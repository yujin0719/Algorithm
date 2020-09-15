// 18406: 럭키 스트레이트
n = input()

first = n[:len(n)//2]
second = n[len(n)//2:]
sum_f = 0
sum_s = 0

for num in range(len(first)):
  sum_f += int(first[num])
  sum_s += int(second[num])

if sum_f == sum_s:
  print("LUCKY")
else:
  print("READY")
