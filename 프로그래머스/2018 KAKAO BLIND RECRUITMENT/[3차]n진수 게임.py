# [3차]n진수 게임
def convert(total,base):
    char = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
    result = '0'
    num = 0
    while len(result) <= total:
        cur = num
        tmp = ''
        while cur > 0:
            tmp += char[cur % base]
            cur //= base
        result += tmp[::-1]
        num += 1
    return result

def solution(n, t, m, p):
    answer = ''
    numbers = convert(m*t,n)
    for i in range(t):
        answer += numbers[(i*m)+p-1]
    return answer 