#  좌물쇠와 열쇠
# 2차원 리스트 90도 회전하기
def rotate(a):
    n = len(a)
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n - i - 1] = a[i][j]
    return result

# 자물쇠의 중간 부분이 모두 1인지 확인
def check(new_lock):
    lock_length = len(new_lock) // 3
    for i in range(lock_length, lock_length * 2):
        for j in range(lock_length, lock_length * 2):
            if new_lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    temp = [[0] * (n * 3) for _ in range(n * 3)]
    for i in range(n):
        for j in range(n):
            temp[i + n][j + n] = lock[i][j]

    # 4가지 방향
    for rotation in range(4):
        key = rotate(key)
        for x in range(n * 2):
            for y in range(n * 2):
                # 자물쇠에 열쇠를 끼워 넣기
                for i in range(m):
                    for j in range(m):
                        temp[x + i][y + j] += key[i][j]
                # 새로운 자물쇠에 열쇠가 정확히 들어 맞는지 검사
                if check(temp) == True:
                    return True
                # 자물쇠에서 열쇠를 다시 빼기
                for i in range(m):
                    for j in range(m):
                        temp[x + i][y + j] -= key[i][j]
    return False
