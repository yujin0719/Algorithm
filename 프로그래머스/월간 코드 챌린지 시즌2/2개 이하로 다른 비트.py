# 2개 이하로 다른 비트
def solution(numbers):
    answer = []
    for number in numbers:
        if number % 2 == 0:
            answer.append(number+1)
        else:
            num = list('0' + bin(number)[2:])
            for i in range(len(num)-1,-1,-1):
                if num[i] == '0':
                    num[i] = '1'
                    num[i+1] = '0'
                    num = "0b"+"".join(num)
                    answer.append(int(num,2))
                    break
    return answer