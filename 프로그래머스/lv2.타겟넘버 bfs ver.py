# 타켓넘버 BFS로
from collections import deque
def solution(numbers, target):
    answer = 0
    queue = deque([(0,0)])
    while queue:
        total, idx = queue.popleft()
        if idx == len(numbers):
            if total == target:
                answer += 1
        else :
            number = numbers[idx]
            queue.append((total+number,idx+1))
            queue.append((total-number,idx+1))
    return answer
