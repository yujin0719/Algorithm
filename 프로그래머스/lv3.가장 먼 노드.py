# Level3: 가장 먼 노드
def solution(n, edge):
    connect = {x:set() for x in range(1,n+1)}
    for e in edge:
        connect[e[0]].add(e[1])
        connect[e[1]].add(e[0])
    queue = [1]
    check = [-1 for _ in range(n)]
    check[0] = 0
    while queue:
        cur = queue.pop(0)
        for node in connect[cur]:
            if check[node-1] == -1:
                check[node-1] = check[cur-1]+1
                queue.append(node)
    m = max(check)
    answer = sum([1 for x in check if x == m])
    return answer