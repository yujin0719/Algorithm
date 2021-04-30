# Level2: 가장 큰 수
def solution(numbers):
    answer = ''
    number = [str(n) for n in numbers]
    number.sort(key = lambda x : x*3 , reverse = True)
    answer = int("".join(number))
    return str(answer)