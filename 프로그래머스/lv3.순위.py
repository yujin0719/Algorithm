# Level3: 순위
def solution(n, results):
    answer = 0
    win = {x:set() for x in range(1,n+1)}
    lose = {x:set() for x in range(1,n+1)}
    
    for w,l in results:
        win[w].add(l)
        lose[l].add(w)
        
    for i in range(1,n+1):
        for winner in win[i]:
            lose[winner].update(lose[i])
        for loser in lose[i]:
            win[loser].update(win[i])
    
    for i in range(1,n+1):
        if len(lose[i]) + len(win[i]) == n-1:
            answer += 1
    
    return answer