// 11048: 이동하기

#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[1001][1001], dp[1001][1001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  dp[0][0] = board[0][0];
  for(int i = 1; i < n; i++) dp[i][0] = dp[i-1][0]+board[i][0];
  for(int i = 1; i < m; i++) dp[0][i] = dp[0][i-1]+board[0][i];
  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++)
      dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1])) + board[i][j];
  cout << dp[n-1][m-1];
}
