# Level2: 삼각 달팽이
def solution(n):
    answer = []
    dx = [1,0,-1]
    dy = [0,1,-1]
    board = [[0]*(n) for _ in range(n)]
    cur = 1
    i,j = 0,0
    direction = 0
    while (n*(n+1)) // 2 >= cur:
        if 0 <= i < n and 0 <= j < n and board[i][j] == 0:
            board[i][j] = cur
            cur += 1
        else:
            i -= dx[direction]
            j -= dy[direction]
            direction = (direction+1) % 3
        i += dx[direction]
        j += dy[direction]

    for i in range(n):
        for j in range(0,i+1):
            answer.append(board[i][j])
    return answer
