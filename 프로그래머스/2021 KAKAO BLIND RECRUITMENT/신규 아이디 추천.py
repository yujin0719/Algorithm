# 신규 아이디 추천
def solution(new_id):
    answer = ""
    # 1단계
    new_id = new_id.lower()
    # 2단계
    for word in new_id:
        if word.isalpha() or word.isdigit() or word == '-' or word == '_' or word == '.':
            answer += word
    # 3단계
    tmp = ''
    while True:
        tmp = answer.replace('..','.')
        if len(tmp) == len(answer):
            break
        answer = tmp
    # 4단계
    answer = answer.lstrip(".").rstrip(".")
    # 5단계
    if len(answer) == 0:
        answer = 'a'
    # 6단계
    if len(answer) >= 16:
        answer = answer[:15].rstrip('.')
    # 7단계
    if len(answer) <= 2:
        answer = answer + answer[-1]*3 
        answer = answer[:3]
    return answer