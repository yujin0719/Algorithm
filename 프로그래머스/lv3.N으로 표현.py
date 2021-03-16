# Level3: N으로 표현
def solution(N, number):
    if N == number:
        return 1
    s = [set() for _ in range(8)]
    for idx, x in enumerate(s):
        x.add(int(str(N)*(idx+1)))
    for i in range(1,len(s)):
        for j in range(i):
            for op1 in s[j]:
                for op2 in s[i-j-1]:
                    s[i].add(op1+op2)
                    s[i].add(op1*op2)
                    s[i].add(op1-op2)
                    if op2 != 0:
                        s[i].add(op1 // op2)
        print(s)
        if number in s[i]:
            return i+1
    return -1