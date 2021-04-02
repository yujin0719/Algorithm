# Level2: 메뉴 리뉴얼
from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for menu in course:
        menus = []
        for order in orders:
            candidates = combinations(sorted(order), menu)
            menus += candidates
        cnt = Counter(menus)
        if len(cnt) != 0 and max(cnt.values()) > 1:
            answer += ["".join(x) for x in cnt if cnt[x] == max(cnt.values())]
    return sorted(answer)