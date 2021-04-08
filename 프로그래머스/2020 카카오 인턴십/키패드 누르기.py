# 키패드 누르기 (20분 소요)
def solution(numbers, hand):
    answer = ''
    left, right = 10, 12
    for num in numbers:
        if num == 0:
            num = 11
        if num % 3 == 1:
            answer += 'L'
            left = num
        elif num % 3 == 0:
            answer += 'R'
            right = num
        # 거리계산
        else:
            dist_l = abs(left//3 - num//3) if left % 3 == 2 else abs((left//3) -(num // 3)) + 1
            dist_r = abs(right//3 - num//3) if right % 3 == 2 else abs((right//3-1) -(num // 3)) + 1
            if dist_l > dist_r:
                answer += 'R'
                right = num
            elif dist_l < dist_r:
                answer += 'L'
                left = num
            else:
                if hand == 'right':
                    answer += 'R'
                    right = num
                else:
                    answer += 'L'
                    left = num
    return answer