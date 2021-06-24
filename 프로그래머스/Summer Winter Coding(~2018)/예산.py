# 예산
def solution(d, budget):
    answer = 0
    total = 0 
    d.sort()
    for price in d:
        if total + price > budget:
            return answer
        answer += 1
        total += price
    return answer