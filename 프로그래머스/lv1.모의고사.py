# Level1: 모의고사
def solution(answers):
    answer = []
    result = []
    student = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    for i in range(3):
        cnt = 0;
        for idx,a in enumerate(answers):
            if a == student[i][idx%len(student[i])]:
                cnt += 1
        result.append(cnt)
    max_num = max(result)
    for i in range(3):
        if max_num == result[i]:
            answer.append(i+1)
    return answer