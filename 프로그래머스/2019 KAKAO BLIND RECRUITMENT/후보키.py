# 후보키
from itertools import combinations
def check(relation, candidate):
    new_relation = []
    for r in relation:
        row = []
        for c in candidate:
            row.append(r[c])
        new_relation.append(tuple(row))
    if len(relation) == len(set(tuple(new_relation))):
        return True
    return False

def solution(relation):
    result = []
    idx = [i for i in range(len(relation[0]))]
    for i in range(1,len(relation[0])+1,1):
        candidates = list(combinations(idx,i))
        for candidate in candidates:
            # 유일성       
            if check(relation, candidate):
                # 최소성
                flag = True
                for r in result:
                    if set(r) & set(candidate) == set(r) or set(r) & set(candidate)  == set(candidate):
                        flag = False
                        break
                if flag:
                    result.append(candidate)
    return len(result)