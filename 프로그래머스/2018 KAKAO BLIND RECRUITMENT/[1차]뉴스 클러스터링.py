# 뉴스 클러스터링
from collections import defaultdict
def solution(str1, str2):
    answer = 0
    dict1 = defaultdict(int)
    dict2 = defaultdict(int)
    set1,set2 = set(),set()
    for i in range(0,len(str1)-1):
        tmp = str1[i:i+2]
        if tmp.isalpha():
            dict1[tmp.upper()] += 1
            set1.add(tmp.upper())
    for i in range(0,len(str2)-1):
        tmp = str2[i:i+2]
        if tmp.isalpha():
            dict2[tmp.upper()] += 1
            set2.add(tmp.upper())
    inter = set1 & set2
    union = set1 | set2
    if len(union) == 0 or len(dict2) == 0:
        return 65536
    total_inter, total_union = 0,0
    for i in inter:
        total_inter += min(dict1[i],dict2[i])
    for u in union:
        total_union += max(dict1[u],dict2[u])
    return int(total_inter / total_union * 65536)