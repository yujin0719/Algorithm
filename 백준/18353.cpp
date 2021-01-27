// 18353: 병사 배치하기

#include <bits/stdc++.h>
using namespace std;
int n;
int man[2000];
int dp[2000];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> man[i];
  fill(dp,dp+n,1);
  int maxValue = 1;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(man[i] < man[j]){
        dp[i] = max(dp[j]+1,dp[i]);
      }
      maxValue = max(maxValue, dp[i]);
    }
  }
  cout << n-maxValue;
}
