# Level3: 디스크 컨트롤러
import heapq
def solution(jobs):
    # n: job의 개수, cnt: 처리한 job의 개수
    n, time, last, cnt = len(jobs), 0, -1, 0
    queue = []
    answer = 0
    while cnt < n:
        for job in jobs:
            if last < job[0] <= time:
                # 현재시간기준으로 job이 얼마나 queue에서 기다렸는가                    
                answer += (time - job[0])
                heapq.heappush(queue,job[1])
        if queue:
            # 가장 빨리 끝나는 작업이 끝날때 까지 나머지 job은 대기해야하므로 대기시간을 추가               
            answer += (len(queue) * queue[0])
            last = time
            time += heapq.heappop(queue)
            cnt += 1
        else :
            time += 1
    return answer // n