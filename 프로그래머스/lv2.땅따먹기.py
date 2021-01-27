# Level2: 땅따먹기

def solution(land):
    dp = [[0]*4 for _ in range(len(land))]
    dp[0] = [a for a in land[0]]
    for i in range(1,len(land)):
        dp[i][0] = max(dp[i-1][1],dp[i-1][2],dp[i-1][3]) + land[i][0]
        dp[i][1] = max(dp[i-1][0],dp[i-1][2],dp[i-1][3]) + land[i][1]
        dp[i][2] = max(dp[i-1][0],dp[i-1][1],dp[i-1][3]) + land[i][2]
        dp[i][3] = max(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + land[i][3]
    return max(dp[len(land)-1])
