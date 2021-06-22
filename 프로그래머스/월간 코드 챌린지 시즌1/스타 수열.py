# 스타 수열
from collections import Counter
def solution(a):
    answer = 0
    cnt = Counter(a)
    for element in cnt:
        if cnt[element] <= answer:
            continue
        total = 0
        idx = 0
        while idx < len(a) - 1:
            if((a[idx] != element and a[idx+1] != element) or a[idx] == a[idx+1]):
                idx += 1
                continue
            total += 1
            idx += 2
        answer = max(total,answer)
    return answer*2