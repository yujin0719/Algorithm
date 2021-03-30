# Level3. 이중우선순위큐 => 만약 효율성이 있었으면 이렇게 풀어야 할듯
import heapq
def solution(operations):
    queue = []
    for operation in operations:
        command,number = operation.split(" ")
        if command == "I":
            heapq.heappush(queue,int(number))
        else :
            if len(queue) > 0:
                if number == '1':
                    queue.pop(queue.index(heapq.nlargest(1,queue)[0]))
                else:
                    heapq.heappop(queue)
    if len(queue) == 0:
        return [0,0]
    return [heapq.nlargest(1,queue)[0],heapq.nsmallest(1,queue)[0]]