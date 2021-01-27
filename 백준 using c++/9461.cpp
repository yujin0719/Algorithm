// 9461: 파도반 수열

#include <bits/stdc++.h>
using namespace std;
int t,n;
long long dp[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  for(int i = 4; i <= 100; i++)
    dp[i] = dp[i-2] + dp[i-3];
  while(t--){
    cin >> n;
    cout << dp[n] << "\n";
  }
}         
