# Level2: 폰켓몬

def solution(nums):
    n = len(nums)
    nums = list(set(nums))
    return n//2 if n//2 < len(nums) else len(nums)
