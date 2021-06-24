# 약수의 개수와 덧셈

def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if int(i**0.5)==i**0.5:
            answer -= i
        else:
            answer += i
    return answer

# 처음에 푼 방식
# def prime(num):
#     result = 0
#     for i in range(1,num+1):
#         if num % i == 0:
#             result += 1
#     return result
# def solution(left, right):
#     answer = 0
#     for num in range(left,right+1):
#         if prime(num) % 2 == 0:
#             answer += num
#         else :
#             answer -= num
#     return answer
