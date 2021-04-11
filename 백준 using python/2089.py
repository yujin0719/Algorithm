# 2089: -2진수
n = int(input())
answer = ''
while n :
	if n % (-2):
		answer = '1' + answer
		n = n // -2 + 1
	else :
		answer = '0' + answer
		n = n // -2
print('0') if answer == '' else print(answer)