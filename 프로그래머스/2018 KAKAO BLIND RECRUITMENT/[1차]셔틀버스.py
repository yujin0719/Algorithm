# 셔틀버스
def solution(n, t, m, timetable):
    for idx, time in enumerate(timetable):
        time = time.split(":")
        timetable[idx] = int(time[0])*60 + int(time[1])
    timetable.sort()
    last = 540 + (n-1) * t
    for bus in range(n):   
        if len(timetable) < m:
            return '%02d:%02d' %(last // 60, last % 60)
        # 마지막 버스까지 온 경우
        if bus == n-1:
            # 남은 대기자의 첫번째 사람이 last 보다 일찍 줄을 섰다면,             
            if timetable[0] <= last:
                # 제일 마지막으로 버스를 탈 수 있는 사람보다 1분 앞서게 한다. 
                last = timetable[m-1] - 1
            return '%02d:%02d' %(last // 60, last % 60)
        for i in range(m-1,-1,-1):
            bus_time = 540 + (bus * t)
            if timetable[i] <= bus_time:
                del timetable[i]