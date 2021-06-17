# 압축
def solution(msg):
    answer = []
    dict = {}
    for i in range(26):
        dict[chr(i+65)] = i+1
    total = 27
    last = 1
    while len(msg) > 0:
        l = last if len(msg) > last else len(msg)
        while True:
            word = msg[:l]
            if word in dict:
                answer.append(dict[word])
                if len(word) != len(msg):
                    dict[word + msg[l]] = total
                    total += 1
                    last = len(word)+1 if len(word)+1 > last else last
                msg = msg[l:]
                break
            else:
                l -= 1
    return answer