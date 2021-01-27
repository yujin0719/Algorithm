// 10844: 쉬운 계단 수
#include <bits/stdc++.h>
using namespace std;
int n;
long long result = 0;
int dp[101][10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= 9; i++)
    dp[1][i] = 1;
  for(int i = 2; i <= n; i++){
    for(int j = 1; j < 9; j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
    }
    dp[i][0] = dp[i-1][1];
    dp[i][9] = dp[i-1][8];
  }
  for(int i = 0; i < 10; i++) result += dp[n][i];
  cout << result % 1000000000;
}
