#Level3 : 줄 서는 방법
import math
def solution(n, k):
    answer = []
    number = [i+1 for i in range(n)]
    total, stage = 1, n-1
    while number:
        for i in range(1,len(number)+1):
            if k < total + math.factorial(stage) * i:
                answer.append(number[i-1])
                total += (math.factorial(stage) * (i-1))
                del number[i-1]
                stage -= 1
                break
    return answer