# Level1 완주하지 못한 선수
def solution(participant, completion):
    participant.sort()
    completion.sort()
    completion.append(" ")
    for p,c in zip(participant,completion):
        if p != c :
            return p