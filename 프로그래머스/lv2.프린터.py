# Level2: 프린터
from collections import deque
def solution(priorities, location):
    answer = 0
    queue = deque()
    for idx, priority in enumerate(priorities):
        queue.append([priority,idx])
    while queue:
        priority, idx = queue.popleft()
        if queue and max(queue)[0] > priority:
            queue.append([priority,idx])
        else:
            answer += 1
            if location == idx:
                return answer
