# 합승택시 요금
def solution(n, s, a, b, fares):
    inf = 1000000000
    answer = inf
    cost = [[inf]*(n+1) for _ in range(n+1)]
    for c1,c2,fare in fares:
        cost[c1][c2] = fare
        cost[c2][c1] = fare
    for i in range(1,n+1):                              
        cost[i][i] = 0
    for i in range(1,n+1):
        for j in range(1,n+1):
            for k in range(1,n+1):
                if j != k and cost[j][k] > cost[j][i] + cost[i][k]:
                    cost[j][k] = cost[j][i] + cost[i][k]
                    cost[k][j] = cost[j][i] + cost[i][k]
    for i in range(1,n+1):
        result = cost[i][s] + cost[i][a] + cost[i][b]
        answer = min(answer,result)
    return answer