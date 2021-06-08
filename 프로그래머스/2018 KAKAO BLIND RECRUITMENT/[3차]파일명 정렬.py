# [3차] 파일명 정렬
from collections import defaultdict
def solution(files):
    answer = []
    dict = defaultdict(list)
    for idx,file in enumerate(files):
        number_idx = 0
        for i,f in enumerate(file):
            if number_idx == 0 and f.isdigit():
                number_idx = i
            if number_idx != 0 and not f.isdigit():
                head = file[:number_idx].upper()
                number = int(file[number_idx:i])
                dict[head].append([number,idx])
                break
            elif number_idx != 0 and len(file) == i+1:
                head = file[:number_idx].upper()
                number = int(file[number_idx:i+1])
                dict[head].append([number,idx])
                break
    dict = sorted(dict.items())
    for head in dict:
        number = head[1]
        number.sort(key = lambda x : x[0])
        for num in number:
            answer.append(files[num[1]])
    return answer