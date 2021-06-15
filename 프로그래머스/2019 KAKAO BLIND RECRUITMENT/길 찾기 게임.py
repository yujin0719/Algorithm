# 길 찾기 게임
import sys
sys.setrecursionlimit(10**6)

def preorder(last,result):
    if len(last) == 0:
        return result
    last.sort(key = lambda x : x[1])
    root = last[-1]
    result.append(root[2])
    left = [node for node in last if node[0] < root[0]]
    right = [node for node in last if node[0] > root[0]]
    preorder(left,result)
    preorder(right,result)
    return result

def postorder(last,result):
    if len(last) == 0:
        return result
    last.sort(key = lambda x : x[1])
    root = last[-1]
    left = [node for node in last if node[0] < root[0]]
    right = [node for node in last if node[0] > root[0]]
    postorder(left,result)
    postorder(right,result)
    result.append(root[2])
    return result

def solution(nodeinfo):
    answer = []
    for idx,node in enumerate(nodeinfo):
        nodeinfo[idx].append(idx+1)
    answer.append(preorder(nodeinfo,[]))
    answer.append(postorder(nodeinfo,[]))
    return answer