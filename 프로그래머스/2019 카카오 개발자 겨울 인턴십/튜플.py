# 튜플
def solution(s):
    answer = []
    s = s[2:-2].split("},{")
    s.sort(key = lambda x : len(x))
    for nums in s:
        nums = map(int,nums.split(","))
        for num in nums:
            if num not in answer:
                answer.append(num)
                break
    return answer