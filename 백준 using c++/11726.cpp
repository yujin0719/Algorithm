// 11726: 2Xn 타일링

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= n; i++)
    dp[i] = (dp[i-1]+dp[i-2])%10007;
  cout << dp[n];
}
