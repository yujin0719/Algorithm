// 11053: 가장 긴 증가하는 부분 수열
// maxValue를 1로 초기화해야한다. (초기 수열의 길이가 1일 수 있으므로)
// --> 99% 부분에서 error 원인

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1000];
int numbers[1000];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> numbers[i];
  int maxValue = 1;
  fill(dp,dp+n,1);
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(numbers[i] > numbers[j])
        dp[i] = max(dp[i],dp[j]+1);
      maxValue = max(dp[i], maxValue);
    }
  }
  cout << maxValue;
}
