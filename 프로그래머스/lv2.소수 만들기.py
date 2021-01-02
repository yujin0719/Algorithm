# Level2: 소수 만들기

from itertools import combinations
def isPrime(num):
    for i in range(2,int(num**0.5)+1):
        if num % i == 0:
            return False
    return True

def solution(nums):
    answer = 0
    candidates = combinations(nums,3)
    for c in candidates:
        if isPrime(sum(c)):
            answer += 1
    return answer
