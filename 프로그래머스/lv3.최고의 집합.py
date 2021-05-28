# Level3: 최고의 집합
def solution(n, s):
    if n > s:
        return [-1]
    portion,remain = s // n , s % n
    answer = [portion] * n
    for idx in range(remain):
        answer[idx] += 1
    return  sorted(answer)