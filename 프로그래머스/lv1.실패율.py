# level1: 실패율

def solution(N, stages):
    result = {}
    deno = len(stages)
    for stage in range(1,N+1):
        if deno != 0:
            count = stages.count(stage)
            result[stage] = count / deno
            deno -= count
        else :
            result[stage] = 0
    return sorted(result,key = lambda x : result[x], reverse = True)
