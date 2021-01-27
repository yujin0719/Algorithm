# level2 : 이진 변환 반복하기

def solution(s):
    answer = []
    cnt = 0
    z = 0
    while True:
        one = s.count('1')
        zero = s.count('0')
        if s == '1':
            break
        else :
            cnt += 1
            z += zero
        s = bin(one)[2:]
    answer.append(cnt)
    answer.append(z)
    return answer
