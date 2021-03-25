# Level3 단어변환
from collections import deque
def solution(begin, target, words):
    answer = 0
    check = [0 for _ in range(len(words))]
    queue = deque()
    queue.append(begin)
    while queue:
        cur = queue.popleft()
        if cur == target:
            return check[words.index(cur)]
        for i in range(len(words)):
            if check[i] == 0:
                if sum([x!=y for x,y in zip(cur,words[i])]) == 1:
                    queue.append(words[i])
                    if cur == begin:
                        check[i] = 1
                    else:
                        check[i] = check[words.index(cur)] + 1
    return 0