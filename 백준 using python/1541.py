# 1541: 잃어버린 괄호
import re
expression = input()

ex = re.split(r'\b',expression)[1:-1]
idx = 0 
while idx < len(ex):
	if ex[idx] == '+':
		cal = int(ex[idx-1])+int(ex[idx+1])
		del ex[idx-1:idx+2]
		ex.insert(idx-1,str(cal))
	else :
		idx += 1
for i in range(len(ex)):
	if ex[i].isdigit():
		ex[i]= str(int(ex[i]))
print(eval(''.join(map(str,ex))))