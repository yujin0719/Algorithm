#[3차] 방금그곡
def solution(m, musicinfos):
    result = []
    origin = ['C#','D#','F#','G#','A#']
    replace = ['c','d','f','g','a']
    # '#'처리하기
    for idx,o in enumerate(origin):
        m = m.replace(o,replace[idx])
    for number,music in enumerate(musicinfos):
        music = music.split(",")
        start,end =  list(map(int,music[0].split(":"))),list(map(int,music[1].split(":")))
        s,e = start[0] * 60 + start[1] , end[0] * 60 + end[1]
        time = e - s
        # '#'처리하기
        for idx,o in enumerate(origin):
            music[3] = music[3].replace(o,replace[idx])
        lyrics = list(music[3])
        play = ''
        size = len(lyrics)
        for t in range(time):
            play += lyrics[t % size]
        if m in play:
            result.append([time,number,music[2]])
    
    if len(result) == 1:
        return result[0][2]
    elif len(result) == 0:
        return '(None)'
    else:
        result.sort(key = lambda x : x[0], reverse = True)
        if result[0][0] != result[1][0]:
            return result[0][2]
        else:
            result.sort(key = lambda x : x[1])
            return result[0][2]