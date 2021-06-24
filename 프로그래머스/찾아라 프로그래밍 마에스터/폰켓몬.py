# 폰켓몬
def solution(nums):
    set_nums = set(nums)
    return min(len(nums) // 2, len(set_nums))