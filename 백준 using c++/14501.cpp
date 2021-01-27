// 14501: 퇴사
// 이것도 역시... 인덱스 주의
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> t;
vector<int> p;
int dp[16];
int maxValue;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    t.push_back(a);
    p.push_back(b);
  }

  for(int i = n-1; i >= 0; i--){
    int time = i + t[i];
    if(time <= n){
      dp[i] = max(maxValue, p[i] + dp[time]);
      maxValue = dp[i];
    }
    else dp[i] = maxValue;
  }
  cout << maxValue;
}
