//1149: RGB 거리
#include <bits/stdc++.h>
using namespace std;
int n;
int home[1001][3];
int dp[1001][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i ++)
    cin >> home[i][0] >> home[i][1] >> home[i][2];
  dp[0][0] = home[0][0];
  dp[0][1] = home[0][1];
  dp[0][2] = home[0][2];
  for(int i  = 1;  i < n; i++ ){
    dp[i][0] = home[i][0] + min(dp[i-1][1],dp[i-1][2]);
    dp[i][1] = home[i][1] + min(dp[i-1][0],dp[i-1][2]);
    dp[i][2] = home[i][2] + min(dp[i-1][0],dp[i-1][1]);
  }
  cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
}
