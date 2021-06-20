# Level2: 조이스틱
def solution(name):
    answer = 0
    position = 0
    vertical = [min(ord(n) - ord('A'), ord('Z') - ord(n) + 1) for n in name]
    while True:
        answer += vertical[position]
        vertical[position] = 0 
        if sum(vertical) == 0:
            return answer
        left,right = 1,1
        while vertical[position - left] == 0:
            left += 1
        while vertical[right + position] == 0:
            right += 1
        if left >= right :
            answer += right
            position += right
        else :
            answer += left
            position -= left