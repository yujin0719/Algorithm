# 압축
def solution(msg):
    answer = []
    idx = 0
    words = [chr(w+65) for w in range(26)]
    while True:
        if idx >= len(msg):
            return answer
        tmp = msg[idx]
        while tmp in words and idx < len(msg):
            idx += 1
            if idx >= len(msg):
                break
            tmp += msg[idx]
        if idx >= len(msg):
            answer.append(words.index(tmp)+1)
        else:
            answer.append(words.index(tmp[:-1])+1)
        words.append(tmp)