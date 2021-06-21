# 매칭 점수
import re
from collections import defaultdict
def solution(word, pages):
    answer = 0
    urls = []
    links = defaultdict(list)
    score = defaultdict(list)
    result = 0
    for idx,page in enumerate(pages):
        urls.append(page.split('<meta property="og:url" content="')[1].split('\"')[0])
        body = page.split('<body>')[1].split('</body>')[0]
        for link in body.split('<a href=\"')[1:]:
            links[idx].append(link.split('">')[0])
        text = re.findall(r'[a-zA-Z]+',page.lower())
        basic = 0
        for t in text:
            if t == word.lower():
                basic += 1
        score[idx].append(basic)
        score[idx].append(len(links[idx]))
    
    for i in range(len(pages)):
        link_score = 0
        for link in links:
            if urls[i] in links[link]:
                link_score += (score[link][0] / score[link][1])
        score[i].append(link_score)
        if score[i][0] + score[i][2] > score[result][0] + score[result][2]:
            result = i
    return result