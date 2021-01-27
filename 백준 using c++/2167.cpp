// 2167: 2차원 배열의 합
#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,x,y;
int board[301][301],dp[301][301];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <=n; i++)
    for(int j = 1; j <=m; j++)
      cin >> board[i][j];
  for(int i = 1; i <= n; i++)
    dp[i][1] = board[i][1]+dp[i-1][1];
  for(int i = 1; i <= m; i++)
    dp[1][i] = board[1][i]+dp[1][i-1];
  for(int i = 2; i <= n; i++)
    for(int j = 2; j <= m; j++)
      dp[i][j] = dp[i-1][j] + dp[i][j-1] + board[i][j] - dp[i-1][j-1];

  cin >> k;
  while(k--){
    cin >> i >> j >> x >> y;
    cout << dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1] << "\n";
  }
}
