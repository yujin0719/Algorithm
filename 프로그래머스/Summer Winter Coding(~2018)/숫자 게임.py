# 숫자 게임
from bisect import bisect_right
def solution(A, B):
    A.sort(reverse = True)
    B.sort()
    answer = 0
    for a in A:
        position = bisect_right(B,a)
        if position < len(B):
            del B[position]
            answer += 1
    return answer