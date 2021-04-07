# Level3: 멀리 뛰기
def solution(n):
    a,b = 1,2
    if n < 3:
        return n
    for i in range(3,n+1):
        a, b = b , (a+b) % 1234567
    return b