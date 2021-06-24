# 실패율
from bisect import bisect_left, bisect_right
def solution(N, stages):
    stages.sort()
    start,end = 0,0
    fail = []
    for i in range(1,N+1):
        denominator, numerator = bisect_right(stages,i)-bisect_left(stages,i), len(stages) - bisect_left(stages,i)
        if numerator == 0:
            fail.append([0,i])
        else :
            fail.append([denominator/numerator,i])
    fail.sort(key = lambda x : x[0], reverse = True)
    answer = [f[1] for f in fail]
    return answer