# 11655: ROT13

words = input()
answer = ""
for word in words:
  if word.isalpha():
    if ord(word) <= 90:
      tmp = ord(word) - 13
      if tmp < 65:
        tmp += 26
      answer += chr(tmp)
    else :
      tmp = ord(word) - 13
      if tmp < 97:
        tmp += 26
      answer += chr(tmp)
  else :
    answer += word
print(answer)
