# 10989: 팰린드롬인지 확인하기

alpha = input()
reve = list(reversed(alpha))
if "".join(reve) == alpha:
  print(1)
else:
  print(0)
