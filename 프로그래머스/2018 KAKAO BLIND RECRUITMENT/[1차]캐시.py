# [1차] 캐시
def solution(cacheSize, cities):
    answer = 0
    cache = {}
    for idx,city in enumerate(cities):
        city = city.upper()
        if cacheSize == 0:
            return len(cities)*5
        if len(cache) > 0 and city in cache:
            answer += 1
            cache[city] = idx
        elif len(cache) < cacheSize:
            cache[city] = idx
            answer += 5
        else:
            if city in cache:
                cache[city] = idx
                answer += 1
            else:
                sortedCache = sorted(cache.items(), key = lambda x:x[1])
                del cache[sortedCache[0][0]]
                cache[city] = idx
                answer += 5
    return answer