# 기지국 설치
def solution(n, stations, w):
    answer = 0
    start,end = [],[]
    for station in stations:
        s = station - w if station - w > 1 else 1
        start.append(s)
        e = station + w if station + w <= n else n
        end.append(e)
    cur = 1
    dist = w*2 + 1
    for s,e in zip(start,end):
        count = s - cur
        answer += (count // dist + 1) if count % dist != 0 else count // dist
        cur = e+1
    if e != n:
        count = n - cur + 1
        answer += (count // dist + 1) if count % dist != 0 else count // dist
    return answer