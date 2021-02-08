#  Level2 : 카펫

def solution(brown, yellow):
    x = ((4 + brown) + ((4 + brown)**2 - 16*(brown + yellow)) ** 0.5) // 4
    y = (brown + yellow) // x
    return [x,y]
