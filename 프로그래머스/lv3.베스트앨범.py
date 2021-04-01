# Level3: 베스트앨범
from collections import defaultdict

def solution(genres, plays):
    answer = []
    cnt = defaultdict(int)
    category = defaultdict(list)
    
    for idx,genre in enumerate(genres):
        category[genre].append((idx,plays[idx]))
        cnt[genre] += plays[idx]
    cnt = sorted(cnt.keys(), key = lambda x : cnt[x], reverse = True)
    for genre in cnt:
        songs = sorted(category[genre], key = lambda x : x[1], reverse = True)
        answer += [x[0] for x in songs[:2]]
    return answer