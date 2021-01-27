import sys
input = sys.stdin.readline

dx = [1, 1, -1, -1, 2, 2, -2, -2]
dy = [2, -2, 2, -2, 1, -1, 1, -1]

for _ in range(int(input())):
    l = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    dist = [[0] * l for _ in range(l)]
    q = [start]
    while q:
        cur = q.pop(0)
        if cur[0] == end[0] and cur[1] == end[1]:
            print(dist[cur[0]][cur[1]])
            break
        for i in range(8):
            nx, ny = cur[0] + dx[i], cur[1] + dy[i]
            if nx >= 0 and nx < l and ny >= 0 and ny < l and not dist[nx][ny]:
                q.append((nx, ny))
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1

