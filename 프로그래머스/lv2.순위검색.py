# Level2 순위검색
import bisect
condition  = [['-','cpp','java','python'],['-','backend','frontend'],['-','junior','senior'],['-','chicken','pizza']]
def solution(info, query):
    answer = []
    cases = [[] for _ in range(108)]
    for information in info:
        information = information.split(' ')
        idx = [condition[i].index(information[i]) for i in range(4)]
        idx.append(int(information[-1]))
        for c1 in [0,idx[0]]:
            for c2 in [0,idx[1]]:
                for c3 in [0,idx[2]]:
                    for c4 in [0,idx[3]]:
                        index = c1*27 + c2*9 + c3*3 + c4
                        cases[index].append(idx[-1])
    for i in range(108):
        cases[i].sort()
    for q in query:
        q = q.split(' ')
        queries = [condition[i].index(q[i*2]) for i in range(4)]
        target = int(q[-1])
        index = queries[0]*27 + queries[1]*9 + queries[2]*3 + queries[3]
        answer.append(len(cases[index]) - bisect.bisect_left(cases[index], target))
    return answer