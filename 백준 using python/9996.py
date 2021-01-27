# 9996: 한국이 그리울 땐 서버에 접속하지
# 문제 이해를 잘해야 한다!

n = int(input())
pattern = input().split("*")
first,second = pattern[0],pattern[1]
for _ in range(n):
  words = input()
  if words[:len(first)] == first and words[-len(second):] == second and len(words) >= len("".join(pattern)):
    print("DA")
  else :
    print("NE")
