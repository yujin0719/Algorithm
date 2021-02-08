# Level2: 캐시

def solution(cacheSize, cities):
    answer = 0
    cache = []
    cities = [c.lower() for c in cities]
    if cacheSize == 0:
        return len(cities)*5
    for i in range(len(cities)):
        if cities[i] in cache:
            cache.remove(cities[i])
            cache.append(cities[i])
            answer += 1
        elif len(cache) < cacheSize:
            cache.append(cities[i])
            answer += 5
        else :
            cache = cache[1:]
            cache.append(cities[i])
            answer += 5
    return answer
