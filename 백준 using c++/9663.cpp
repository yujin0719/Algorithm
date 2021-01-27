// 9663: N-Queen

#include <bits/stdc++.h>
using namespace std;
int n,cnt = 0;
bool used1[40]; // column 을 차지하는가
bool used2[40]; // / 방향 대각선을 차지하는가
bool used3[40]; // \ 방향 대각선을 차지하는가

// cur번째 열에 배치
void func(int cur){
  if(cur == n){
    cnt++;
    return;
  }
  for(int i = 0; i < n; i++){ //(cur,i) 에 퀸 놓기
    if(used1[i] || used2[i+cur] || used3[cur-i+n-1]) continue;
    used1[i] = 1;
    used2[i+cur] = 1;
    used3[cur-i+n-1] = 1;
    func(cur+1);
    used1[i] = 0;
    used2[i+cur] = 0;
    used3[cur-i+n-1] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}
