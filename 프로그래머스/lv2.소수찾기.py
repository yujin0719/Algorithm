# Level2: 소수찾기
from itertools import permutations
import math
def solution(numbers):
    answer = 0
    def isPrime(num):
        if num < 2:
            return False
        for i in range(2,int(math.sqrt(num)+1)):
            if num % i == 0:
                return False
        return True
    candidates = set()
    for i in range(1,len(numbers)+1):
        tmp = list(permutations(numbers,i))
        for t in tmp:
            candidates.add(int("".join(t)))
            
    for c in candidates:
        if isPrime(c):
            answer += 1
    return answer