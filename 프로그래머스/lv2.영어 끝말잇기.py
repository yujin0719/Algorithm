# Level2: 영어 끝말잇기

def solution(n, words):
    answer = [0,0]
    for i in range(1,len(words)):
        if words[i][0] != words[i-1][-1] or words[:i].count(words[i]) > 0:
            answer[0] = i % n + 1
            answer[1] = i // n + 1
            break
    return answer
