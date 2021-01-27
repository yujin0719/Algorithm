# Level2: 예상 대진표

def solution(n,a,b):
    answer = 1
    arr = [i+1 for i in range(n)]
    while True:
        for i in range(0,n,2):
            if arr[i] == a and arr[i+1] == b:
                return answer
            if arr[i] == b and arr[i+1] == a:
                return answer
            if arr[i] == a or arr[i+1] == a:
                arr[i//2] = a
            elif arr[i] == b or arr[i+1] == b:
                arr[i//2] = b
            else :
                arr[i//2] = arr[i]
        answer += 1
        n = n//2
    return answer
