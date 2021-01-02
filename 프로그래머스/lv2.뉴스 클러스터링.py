# Level2: 뉴스 클러스터링

def solution(str1, str2):
    answer = 0
    dict1, dict2 = {},{}
    cnt1 , cnt2 = 0,0
    for i in range(len(str1)-1):
        if not str1[i].isalpha() or not str1[i+1].isalpha() :
            continue
        if str1[i:i+2].upper() in dict1:
            dict1[str1[i:i+2].upper()] += 1
        else :
            dict1[str1[i:i+2].upper()] = 1
        cnt1 += 1

    for i in range(len(str2)-1):
        if not str2[i].isalpha() or not str2[i+1].isalpha() :
            continue
        if str2[i:i+2].upper() in dict2:
            dict2[str2[i:i+2].upper()] += 1
        else :
            dict2[str2[i:i+2].upper()] = 1
        cnt2 += 1
    inter = 0
    for d in dict1:
        if d in dict2:
            inter += min(dict1[d],dict2[d])
    answer = inter / (cnt1+cnt2-inter) if cnt1+cnt2-inter != 0 else 1
    answer = int(answer * 65536)
    return answer
