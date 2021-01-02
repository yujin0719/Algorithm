# Level2: 튜플

import functools
def comp(a,b) :
    if len(a) > len(b) :
        return 1
    else:
        return -1
def solution(s):
    answer = []
    arr = list(s[1:-1].split("},"))
    arr[-1] = arr[-1][:-1]
    arr.sort(key = functools.cmp_to_key(comp))
    for a in arr:
        a = a[1:]
        tmp = list(a.split(","))
        for t in tmp:
            if answer.count(int(t)) == 0:
                answer.append(int(t))
    return answer
