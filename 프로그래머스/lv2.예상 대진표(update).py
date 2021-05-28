# Level2: 예상 대진표 ==> 이 방식으로 하는게 더 나은 것 같음
def solution(n,a,b):
    answer = 1
    div = 2
    while True:
        if (a-1) // div == (b-1) // div:
            return answer
        answer += 1
        div *= 2