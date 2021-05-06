# Level2: 멀쩡한 사각형
def solution(w,h):
    answer = 1
    def GCD(a,b):
        if b == 0: return a
        if a % b == 0: return b
        else: return GCD(b,a % b)
    gcd = GCD(w,h)
    return w*h - (w+h-gcd)