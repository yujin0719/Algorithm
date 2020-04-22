//2448 : 별찍기-11
#include <bits/stdc++.h>
using namespace std;
int N;
char board[3072][6144];

void star(int num, int x, int y){
  if(num==3){
    board[y][x] = '*';
    board[y+1][x-1]= '*';
    board[y+1][x+1] = '*';
    board[y+2][x-2] = '*';
    board[y+2][x-1] = '*';
    board[y+2][x] = '*';
    board[y+2][x+1] = '*';
    board[y+2][x+2] = '*';
    return;
  }
  star(num/2,x,y);
  star(num/2,x-(num/2),y+(num/2));
  star(num/2,x+(num/2),y+(num/2));
}

int main(void){
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<2*N; j++){
      if(j==2*N-1)
        board[i][j] = '\0';
      else
        board[i][j] = ' ';
    }
  }
  star(N,N-1,0);
  for(int i = 0; i < N; i++){
    for(int j=0; j < 2*N-1; j++)
      cout << board[i][j];
    cout << '\n';
  }
  return 0;
}
