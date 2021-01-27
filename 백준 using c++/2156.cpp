// 2156: 포도주 시식

#include <bits/stdc++.h>
using namespace std;
int n;
int drink[10001];
int dp[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> drink[i];
  dp[0] = 0;
  dp[1] = drink[1];
  dp[2] = drink[1] + drink[2];
  for(int i = 3; i <= n; i++)
    dp[i] = max(dp[i-1],max(drink[i]+dp[i-2],drink[i]+drink[i-1]+dp[i-3]));
  cout << dp[n];
}
