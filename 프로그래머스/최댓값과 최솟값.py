# 최댓값과 최솟값
def solution(s):
    answer = ''
    numbers = list(map(int,s.split(" ")))
    numbers.sort()
    return str(numbers[0]) + " " + str(numbers[-1])