// 2294: 동전2
#include <bits/stdc++.h>
using namespace std;
int n,k;
int coin[101],dp[10001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> coin[i];
  for(int i = 0; i <= k; i++) dp[i] = 0xfffffff;
  for(int i = 0; i < n; i++){
    if(coin[i] > k) continue;
    dp[coin[i]] = 1;
    for(int j = coin[i]+1; j <= k; j++){
      dp[j] = min(dp[j],dp[j-coin[i]]+1);
    }
  }
  if(dp[k] == 0xfffffff) cout << -1;
  else cout << dp[k];
}
