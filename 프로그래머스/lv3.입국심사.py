# Level3: 입국심사
def solution(n, times):
    answer = 0
    examiner = len(times)
    left,right = 1, max(times) * n
    while left <= right:
        mid = (left + right) // 2
        cnt = 0
        for time in times:
            cnt += (mid // time)
            if cnt >= n:
                break
        if cnt >= n:
            answer = mid 
            right = mid - 1
        else:
            left = mid + 1
    return answer