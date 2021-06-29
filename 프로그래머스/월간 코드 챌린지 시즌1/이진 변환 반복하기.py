# 이진 변환 반복하기
def solution(s):
    times,zero = 0,0
    while s != '1':
        times += 1
        zero += len(s)
        s = s.replace("0","")
        zero -= len(s)
        s = bin(len(s))[2:]
    return [times,zero]