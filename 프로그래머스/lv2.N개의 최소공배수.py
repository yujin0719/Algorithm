# Level2: N개의 최소공배수
def solution(arr):
    arr.sort()
    n,cur = arr[-1],arr[-1]
    while True:
        total = sum([cur % a for a in arr])
        if total == 0:
            break
        cur += n
    answer = cur
    return answer
