# 스킬 트리
from collections import deque
def solution(skill, skill_trees):
    answer = 0
    for tree in skill_trees:
        check = True
        queue = deque(list(skill))
        for t in tree:
            if t in queue and queue[0] == t:
                queue.popleft()
            if t in queue and queue[0] != t:
                check = False
                break
        if check:
            answer += 1
    
    return answer