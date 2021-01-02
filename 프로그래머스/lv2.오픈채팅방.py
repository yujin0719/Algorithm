# Level2: 오픈채팅방

def solution(record):
    answer = []
    dict = {}
    for re in record:
        re = list(re.split(" "))
        if re[0] == "Enter" or re[0] == "Change":
            dict[re[1]] = re[2]
    for re in record:
        re = list(re.split(" "))
        if re[0] == "Enter":
            answer.append(dict[re[1]]+"님이 들어왔습니다.")
        elif re[0] == "Leave":
            answer.append(dict[re[1]]+"님이 나갔습니다.")
    return answer
