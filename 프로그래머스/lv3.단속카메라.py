# Level3: 단속카메리
def solution(routes):
    answer = 0
    routes.sort(key = lambda x : x[1])
    camera = -300001
    for route in routes:
        if route[0] <= camera <= route[1]:
            continue
        answer += 1
        camera = route[1]
    return answer