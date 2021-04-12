# 섬 연결하기 
def solution(n, costs):
    answer = 0
    costs.sort(key = lambda x : x[2])
    connect = set()
    connect.add(0)
    while len(connect) != n:
        for v1,v2,cost in costs:
            if v1 in connect and v2 in connect:
                continue
            if v1 in connect or v2 in connect:
                connect.add(v1)
                connect.add(v2)
                answer += cost
                break
    return answer