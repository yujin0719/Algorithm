# Level3 야근 지수
import heapq
def solution(n, works):
    answer = 0
    heap = []
    for work in works:
        heapq.heappush(heap, (-work,work))
    while True:
        if n == 0 :
            break
        last = heapq.heappop(heap)[1]
        heapq.heappush(heap,(-(last-1),last-1))
        n -= 1
    for h in heap:
        if h[1] <= 0:
            continue
        answer += (h[1]*h[1])
    return answer