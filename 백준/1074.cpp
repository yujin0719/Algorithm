// 1074: Z
#include <bits/stdc++.h>
using namespace std;
int N,r,c,cnt =0;

void Z(int size, int row, int column){
  if(size == 2){
    if(row == r && column == c){
      cout << cnt;
      return;
    }
    cnt++;
    if(row == r && column+1 == c){
      cout << cnt;
      return;
    }
    cnt++;
    if(row+1 == r && column == c){
      cout << cnt;
      return;
    }
    cnt++;
    if(row+1 == r && column+1 == c){
      cout << cnt;
      return;
    }
    cnt++;
    return;
  }
  Z(size/2,row,column);
  Z(size/2,row,column+size/2);
  Z(size/2,row+size/2,column);
  Z(size/2,row+size/2,column+size/2);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> r >> c;
  Z(1 << N, 0, 0);
}
