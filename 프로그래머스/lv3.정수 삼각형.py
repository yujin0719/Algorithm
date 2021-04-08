# Level3: 정수 삼각형
def solution(triangle):
    answer = 0
    dp = triangle[::]
    for i in range(len(triangle)-2,-1,-1):
        for j in range(0,i+1):
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + dp[i][j]
    return dp[0][0]