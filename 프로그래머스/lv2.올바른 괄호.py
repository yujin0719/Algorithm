# Level2: 올바른 괄호

def solution(s):
    answer = True
    stack = []
    for tmp in s :
        if tmp == '(':
            stack.append('(')
        elif len(stack) != 0 and tmp == ')':
            stack.pop()
        else:
            return False
    if len(stack) != 0:
        return False
    return True
