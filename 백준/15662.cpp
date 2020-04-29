//15662: 톱니바퀴(2)
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int k;
  cin >> k;
  while(k--){
    int num, dir;
    cin >> num >> dir;
    // 톱니바퀴를 담는 벡터의 인덱스가 0부터 시작하므로
    num -= 1;
    // 톱니의 회전 방향을 정하는 것 -> 기본 0(회전하지 않음)으로 세팅됨
    vector<int> d(n);
    d[num] = dir;
    // 기준에서 왼쪽 톱니
    for(int i = num-1; i >= 0; i--){
      if(a[i][2] != a[i+1][6]) d[i] = -d[i+1];
      // 회전하지 않으니까 뒤에 톱니도 연쇄적으로 회전하지 않음
      else break;
    }
    // 기준에서 오른쪽 톱니
    for(int i = num+1; i < n; i++){
      if(a[i][6] != a[i-1][2]) d[i] = -d[i-1];
      else break;
    }
    for(int i = 0; i < n; i++){
      // 회전하지 않음
      if(d[i] == 0) continue;
      // 시계방향 회전
      if(d[i] == 1) {
        char temp = a[i][7];
        for(int j = 7; j >= 1; j--) a[i][j] = a[i][j-1];
        a[i][0] = temp;
      }
      // 반시계 방향 회전
      if(d[i] == -1) {
        char temp = a[i][0];
        for(int j = 0; j < 7; j++) a[i][j] = a[i][j+1];
        a[i][7] = temp;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(a[i][0] == '1') ans += 1;
  }
  cout << ans << '\n';
  return 0;
}
