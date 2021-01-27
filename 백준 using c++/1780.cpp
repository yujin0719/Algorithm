// 1780 종이의 개수

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int board[2782][2782];
int N;
int result[3];

void recursion(int N, int x, int y){
  int standard = board[x][y];
  bool flag = true;

  for(int i = x; i < x + N; i++){
    for(int j = y; j < y + N; j++){
      if(board[i][j] != standard){
        flag = false;
        break;
      }
    }
  }
  if(flag) result[standard+1]++;
  else {
    for(int i = x; i < x + N; i += N/3)
      for(int j = y; j < y + N; j += N/3)
        recursion(N/3,i,j);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> board[i][j];
  recursion(N,0,0);
  for(int i = 0; i < 3; i++)
    cout << result[i] << '\n';
  return 0;
}
