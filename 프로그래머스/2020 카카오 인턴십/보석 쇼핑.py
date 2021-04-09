# 보석 쇼핑 (효율성)
from collections import defaultdict
def solution(gems):
    answer = []
    jewelry = len(set(gems))
    result = 100000 
    dict = defaultdict(int)
    left,right = 0,0
    dict[gems[right]] += 1
    while right < len(gems) and left < len(gems):
        if len(dict) == jewelry:
            if result > right-left:
                result = right-left
                answer = [left+1,right+1]
            dict[gems[left]] -= 1
            if dict[gems[left]] == 0:
                del dict[gems[left]]
            left += 1
        else :
            right += 1
            if right == len(gems):
                break
            dict[gems[right]] += 1
    return answer
    