# 3진법 뒤집기
def solution(n):
    answer = 0
    result = ''
    while n > 0 :
        result += str(n%3)
        n //= 3
    
    return int(result,3)