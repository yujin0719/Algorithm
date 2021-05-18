# Level2: 더 맵게
import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville:
        s1 = heapq.heappop(scoville)
        if s1 >= K:
            break
        if len(scoville) == 0:
            return -1
        s2 = heapq.heappop(scoville)
        heapq.heappush(scoville,s1+(s2*2))
        answer += 1
    return answer