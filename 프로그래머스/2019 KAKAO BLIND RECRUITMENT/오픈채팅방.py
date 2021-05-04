# 오픈채팅방
from collections import defaultdict
def solution(record):
    answer = []
    dict = defaultdict(list)
    for r in record:
        r = r.split(" ")
        if r[0] != 'Leave':
            dict[r[1]] = r[2]
    for r in record:
        r = r.split(" ")
        if r[0] == 'Change':
            continue
        if r[0] == 'Enter':
            answer.append(dict[r[1]]+'님이 들어왔습니다.')
        else:
            answer.append(dict[r[1]]+'님이 나갔습니다.')
    return answer