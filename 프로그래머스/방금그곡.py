# 방금그곡
def solution(m, musicinfos):
    sharp = ['C#','D#','F#','G#','A#']
    lowSharp = ['c','d','f','g','a']
    result = {}
    for i in range(5):
        m = m.replace(sharp[i],lowSharp[i])
    for music in musicinfos:
        info = music.split(',')
        lyric = ''
        idx = 0
        for i in range(5):
            info[3] = info[3].replace(sharp[i],lowSharp[i])
        start,end = list(map(int,info[0].split(':'))),list(map(int,info[1].split(':')))
        for i in range(start[0]*60+start[1],end[0]*60+end[1]+1):
            lyric += info[3][idx]
            idx = (idx+1)%len(info[3])
        if m in lyric:
            result[info[2]] = end[0]*60+end[1]-start[0]*60-start[1]+1
    if len(result) == 0:
        return "(None)"
    answer = sorted(result,key = lambda x: result[x],reverse = True)
    return answer[0]