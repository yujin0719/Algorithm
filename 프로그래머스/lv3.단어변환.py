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
                cnt = 0
                for j in range(len(words[i])):
                    if cur[j] == words[i][j]:
                        cnt += 1
                if cnt == len(cur)-1:
                    queue.append(words[i])
                    if cur == begin:
                        check[i] = 1
                    else:
                        check[i] = check[words.index(cur)] + 1
    return 0