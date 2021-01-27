// 16505: 별
// 출력형식 지켜야하기 떄문에 불필요한 공백 주의해야한다. 

#include <bits/stdc++.h>
using namespace std;
int n;
char board[3*1025][3*1025];
void func(int n, int x, int y){
  if(n==0){
    board[x][y] = '*';
    return;
  }
  func(n/2,x,y);
  func(n/2,x+n/2,y);
  func(n/2,x,y+n/2);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < (1<<n); i++) fill(board[i],board[i]+(1<<n),' ');
  func((1<<n),0,0);
  for(int i = 0; i <(1<<n); i++){
    for(int j = 0; j <(1<<n)-i; j++){
      cout << board[i][j];
    }
    cout << '\n';
  }
}
