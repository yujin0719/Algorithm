# level3: 추석트래픽
from datetime import datetime, timedelta

def solution(lines):
    answer = []
    # 1. 시작점과 끝점을 모은 배열
    log = []
    for line in lines:
        logs = line.split(" ")
        date = logs[0] + " " + logs[1]
        end = datetime.fromisoformat(date)
        delay = logs[2][:-1].split(".")
        start = end - timedelta(seconds = int(delay[0]), milliseconds = int(delay[1])-1 if len(delay) > 1 else -1)
        log.append([start,end])
        
    # 2. 시작점과 끝점에 대해 각각 요청량 계산 => 시작과 끝에 요청량이 변화하기 때문
    for times in log:
        for time in times:
            tmp = 0
            start, end = time, time + timedelta(milliseconds=999)
            for data in log:
                if data[0] <= start and data[1] >= start:
                    tmp += 1
                elif data[0] <= end and data[1] >= end:
                    tmp += 1
                elif data[0] <= start and data[1] >= end:
                    tmp += 1
                elif data[0] >= start and data[1] <= end:
                    tmp += 1
            answer.append(tmp)
    return max(answer)