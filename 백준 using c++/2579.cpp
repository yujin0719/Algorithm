// 2579: 계단 오르기
#include <bits/stdc++.h>
using namespace std;
int n;
int stall[301];
int d[301][2];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> stall[i];
  if(n==1){
    cout << stall[0];
    return 0;
  }
  d[0][0] = stall[0];
  d[0][1] = 0;
  d[1][0] = stall[1];
  d[1][1] = stall[0] + stall[1];
  for(int i = 2; i < n; i++) {
    d[i][0] = max(d[i-2][0],d[i-2][1]) + stall[i];
    d[i][1] = d[i-1][0] + stall[i];
  }
  cout << max(d[n-1][0],d[n-1][1]);
}
