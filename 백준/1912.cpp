// 1912: 연속합

#include <bits/stdc++.h>
using namespace std;
int n;
int numbers[100002];
int dp[100002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> numbers[i];
  dp[0] = numbers[0];
  int m = dp[0];
  for(int i = 1; i < n; i++){
    dp[i] = max(dp[i-1]+numbers[i],numbers[i]);
    m = max(m,dp[i]);
  }
  cout << m;
}
