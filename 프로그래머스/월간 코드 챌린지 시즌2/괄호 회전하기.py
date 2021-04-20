# 괄호 회전하기
def solution(s):
    answer = 0
    def check(words):
        open_p,close_p = ['(','[','{'],[')',']','}']
        stack = []
        for w in words:
            if w in open_p:
                stack.append(w)
            else:
                if len(stack) == 0:
                    return False
                elif stack[-1] == open_p[close_p.index(w)]:
                    stack.pop()
                else:
                    return False
        if len(stack) == 0:
            return True
        else :
            return False
        
    for i in range(len(s)):
        words = s[i:]+s[:i]
        if check(words):
            answer += 1    
    return answer