# 섬 연결하기 
def solution(n, costs):
    costs.sort(key = lambda x : x[2])
    connect = []
    parent = [x for x in range(n+1)]
    def find(target):
        if target != parent[target]:
            parent[target] = find(parent[target])
        return parent[target]
    def union(u,v):
        u = find(u)
        v = find(v)
        if u < v:
            parent[v] = u
        else :
            parent[u] = v
    for u,v,w in costs:
        if find(u) != find(v):
            union(u,v)
            connect.append(w)
    return sum(connect)