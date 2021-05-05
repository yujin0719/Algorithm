# 타켓넘버 완점탐색 ver
from itertools import product
def solution(numbers, target):
    l = [(x,-x) for x in numbers]
    s = list(map(sum,product(*l)))
    return s.count(target)