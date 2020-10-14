// 1932: 정수 삼각형
// 인덱스와 개수가 헷갈리지 않게 유의해야한다.
#include <bits/stdc++.h>
using namespace std;
int tri[500][500];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < i+1; j++)
      cin >> tri[i][j];

  for(int i = 1; i < n; i++){
    for(int j = 0; j <= i; j++){
      int left, right;
      if(j == 0) left = 0;
      else left = tri[i-1][j-1];
      if(j == i) right = 0;
      else right = tri[i-1][j];
      tri[i][j] = tri[i][j] + max(left,right);
    }
  }
  int result = 0;
  for(int j = 0; j < n; j++)
    result = max(result,tri[n-1][j]);

  cout << result;
}
