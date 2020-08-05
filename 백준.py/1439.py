// 1439 : 문자열 뒤집기
data = input()

cntzero = 0
cntone = 0
zeroflag = 0
oneflag = 0

for i in range(len(data)):
  if data[i] == '0' and zeroflag == 0:
    cntzero += 1
    zeroflag = 1
    oneflag = 0
  elif data[i] == '1' and oneflag == 0:
    cntone += 1
    zeroflag = 0
    oneflag = 1

print(min(cntzero,cntone))
