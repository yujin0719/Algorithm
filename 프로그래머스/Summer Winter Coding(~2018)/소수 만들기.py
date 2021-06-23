# 소수 만들기
from itertools import combinations
import math
def prime(num):
    for i in range(2,int(math.sqrt(num))+1):
        if num % i == 0:
            return False
    return True
def solution(nums):
    answer = 0
    candidates = list(combinations(nums,3))
    for candidate in candidates:
        if prime(sum(list(candidate))):
            answer += 1
    return answer