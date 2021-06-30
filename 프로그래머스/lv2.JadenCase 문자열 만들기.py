# Level2: JadenCase 문자열 만들기
# def solution(s):
#     answer = ''
#     answer += s[0].upper()
#     for i in range(1,len(s)):
#         if s[i-1] == " ":
#             answer += s[i].upper()
#         else :
#             answer += s[i].lower()
#     return answer

def solution(s):
    s = s.lower().split(" ")
    answer = ''
    for word in s:
        answer += (word.capitalize() + " ")
    return answer[:-1]