 # 2020 카카오 인턴쉽: 수식 최대화
 # 카카오는 문자열 파싱문제가 많이 나오기 때문에 정규표현식을 공부해야겠다...
 
 import re
from itertools import permutations
def solution(expression):
    operators = [x for x in ['*','+','-'] if x in expression]
    operators = [list(x) for  x in permutations(operators)]
    expression = re.split(r'(\D)',expression)
    # 같은 표현: ex = re.split('([-+*])',expression)

    result = []
    for operator in operators:
        # list 복사방법
        ex = expression[:]
        for op in operator:
            while op in ex:
                idx = ex.index(op)
                ex[idx-1] = str(eval(ex[idx - 1] + op + ex[idx + 1]))
                del ex[idx:idx+2]
        result.append(abs(int(ex[0])))
    return max(result)
