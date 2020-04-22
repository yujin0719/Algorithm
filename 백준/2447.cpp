#include <bits/stdc++.h>
using namespace std;
int N;
char board[2300][2300];

void star(int num, int x, int y){
  if(num==1){
    board[x][y] = '*';
    return;
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(i == 1 && j ==1)
        continue;
      star(num/3,x + num / 3 * i, y + num / 3 * j);
    }
  }
}

int main(void){
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      board[i][j] = ' ';
    }
  }
  star(N,0,0);
  for(int i = 0; i < N; i++)
    cout << board[i] << '\n';
  return 0;
}
