# 타켓넘버 dfs ver.
answer = 0
def DFS(idx, numbers, target, value):
    global answer 
    if idx == len(numbers) and target == value:
        answer += 1
        return
    if idx == len(numbers):
        return 
    DFS(idx+1,numbers,target,value+numbers[idx])
    DFS(idx+1,numbers,target,value-numbers[idx])
    
def solution(numbers, target):
    global answer
    DFS(0,numbers,target,0)
    return answer