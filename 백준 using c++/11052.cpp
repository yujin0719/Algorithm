// 11052: 카드 구매하기

#include <bits/stdc++.h>
using namespace std;
int n;
int card[1001],dp[1001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> card[i];
  dp[1] = card[1];
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= i; j++){
      dp[i] = max(dp[i], dp[i-j] + card[j]);
    }
  }
  cout << dp[n];
}
