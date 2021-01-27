// 9465: 스티커
#include <bits/stdc++.h>
using namespace std;
int t,n;
int sticker[100001][2];
int dp[100001][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> sticker[i][0];
    for(int i = 0; i < n; i++) cin >> sticker[i][1];
    dp[0][0] = sticker[0][0];
    dp[0][1] = sticker[0][1];
    dp[1][0] = sticker[1][0] + sticker[0][1];
    dp[1][1] = sticker[1][1] + sticker[0][0];
    for(int i = 2; i < n; i++){
      dp[i][0] = sticker[i][0] + max(dp[i-1][1],dp[i-2][1]);
      dp[i][1] = sticker[i][1] + max(dp[i-1][0],dp[i-2][0]);
    }
    cout << max(dp[n-1][0],dp[n-1][1]) << "\n";
  }
}         
