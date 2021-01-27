# Level2: 점프와 순간 이동

def solution(n):
    answer = 1
    while n > 1:
        if n % 2 != 0:
            answer += 1
        n = n // 2
    return answer
