# Level2: 위장
from collections import defaultdict
def solution(clothes):
    answer = 1
    closet = defaultdict(list)
    for c,t in clothes:
        closet[t].append(c)
    for c in closet:
        answer *= (len(closet[c])+1)
    return answer-1