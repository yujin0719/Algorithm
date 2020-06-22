//14890: 경사로

#include <bits/stdc++.h>
using namespace std;
int ma[100][100];

// 한줄 검사하기 위한 함수
bool go(vector<int> &a, int l){
  int n = a.size();
  // 어떤 칸에 경사로를 놓았는지를 파악하기 위해 사용한 vector
  vector<bool> c(n,false);
  for(int i = 1; i < n; i++){
    // 인접한 칸의 높이가 다르면, 경사로가 필요하다.
    if(a[i-1]!=a[i]){
      int diff = a[i]-a[i-1];
      if(diff < 0) diff = -diff;
      // 낮은칸과 높은칸의 높이 차이가 1이 아니면 경사로를 놓을 수 없다.
      if(diff != 1) return false;
      if(a[i-1] < a[i]){
        // 1. 앞에 칸이 더 작을 때
        for(int j = 1; j <= l; j++){
          // 경사로를 놓는데 범위를 벗어난 경우
          if(i-j < 0) return false;
          // 낮은 지점의 칸의 높이가 모두 같지 않거나 L 개가 연속되지 않은 경우
          if(a[i-1] != a[i-j]) return false;
          //경사로를 놓은 곳에 또 경사로를 놏는 경우
          if(c[i-j]) return false;
          // 위의 세개의 조건에 모두 부합되지 않으면 경사로를 놓을 수 있다는 의미이기 때문에
          c[i-j] = true;
        }
      }
      // 2.  a[i-1] > a[i] 뒤에 칸이 더 작을 때
      else{
        for(int j = 0; j < l; j++){
          // 경사로를 놓다가 범위를 벗어난 경우
          if(i+j >= n) return false;
          // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
          if(a[i] != a[i+j]) return false;
          // 경사로를 놓은 곳에 또 경사로를 놓는 경우
          if(c[i+j]) return false;
          c[i+j] = true;
        }
      }
    }
  }
  return true;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,L;
  cin >> N >> L;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> ma[i][j];

  int result = 0;
  for(int i = 0; i < N; i++){
    vector<int> d;
    for(int j = 0; j < N; j++)
      d.push_back(ma[i][j]);
    if(go(d,L)) result+=1;
  }
  for(int i = 0; i < N; i++){
    vector<int> d;
    for(int j = 0; j < N; j++)
      d.push_back(ma[j][i]);
    if(go(d,L)) result+=1;
  }
  cout << result << '\n';
  return 0;
}
