// 1799: 비숍
// 독립적인 두가지로 나눠서 해야 시간초과 되지 않는다!!!!!

#include <bits/stdc++.h>
using namespace std;
int chess[11][11];
int n, ans[2];
int diagonal[2][20];

void func(int x, int y, int cnt, int color){
  if(y >= n){
    x++;
    if(y % 2 == 0) y = 1;
    else y = 0;
  }
  if(x >= n){
    ans[color] = max(ans[color],cnt);
    return;
  }
  if(chess[x][y] && !diagonal[0][x+y] && !diagonal[1][n-y+x-1]){
    diagonal[0][x+y] = 1;
    diagonal[1][n-y+x-1] = 1;
    func(x,y+2,cnt+1,color);
    diagonal[0][x+y] = 0;
    diagonal[1][n-y+x-1] = 0;
  }
  func(x,y+2,cnt,color);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
       cin >> chess[i][j];

  func(0,0,0,0);
  func(0,1,0,1);
  cout << ans[0]+ans[1];
}
