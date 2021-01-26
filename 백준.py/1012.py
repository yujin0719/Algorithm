import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(int(input())):
    m, n, k = map(int, input().split())
    field = [[0] * m for _ in range(n)]
    cnt = 0
    q = []
    for _ in range(k):
        x, y = map(int, input().split())
        field[y][x] = 1
    for i in range(n):
        for j in range(m):
            if field[i][j] == 1:
                q.append((i, j))
                field[i][j] = 2
                cnt += 1
                while q:
                    cur = q.pop(0)
                    for k in range(4):
                        nx, ny = cur[0] + dx[k], cur[1] + dy[k]
                        if nx >= 0 and nx < n and ny >= 0 and ny < m and field[nx][ny] == 1:
                            q.append((nx, ny))
                            field[nx][ny] = 2
    print(cnt)
