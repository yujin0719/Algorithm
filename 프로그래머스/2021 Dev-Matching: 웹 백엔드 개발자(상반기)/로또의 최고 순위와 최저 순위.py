# 로또의 최고 순위와 최저 순위
def solution(lottos, win_nums):
    right = 0
    for win in win_nums:
        if win in lottos:
            lottos.remove(win)
            right += 1
    possible = [1 for lotto in lottos if lotto == 0]
    row = 7 - right if right > 1 else 6
    high = 7 - (right + len(possible)) if right + len(possible) > 1 else 6
    return [high,row]