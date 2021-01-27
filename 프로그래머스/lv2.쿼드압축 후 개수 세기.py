# level2: 쿼드압축 후 개수 세기

def solution(arr):
    answer = [0,0]
    def check(x,y,n):
        if n == 1:
            return [0, 1] if arr[y][x] == 1 else [1,0]
        left_up = check(x,y, n // 2)
        right_up = check(x + n//2, y, n//2)
        left_down = check(x, y+n//2, n//2)
        right_down = check(x + n//2, y + n//2, n//2)
        if left_up == right_up == left_down == right_down == [0,1] or left_up == right_up == left_down == right_down == [1,0]:
            return left_up
        else:
            return list(map(sum, zip(left_up, right_up, right_down, left_down)))

    result = check(0,0,len(arr))
    return result
