// 15686: 드래곤 커브

#include <bits/stdc++.h>
using namespace std;
int n, x,y,d,g,result = 0;
vector<int> dc[11];
int board[101][101];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 드래곤 커브의 방향 저장해두기
  // 0세대 : 0
  // 1세대 : 0 1
  // 2세대 : 0 1 2 1
  dc[0] = {0};
  for(int i = 1; i < 11; i++){
    dc[i] = dc[i-1];
    for(int j = int(dc[i-1].size())-1; j >= 0; j--){
      dc[i].push_back((dc[i-1][j]+1) % 4);
    }
  }

  cin >> n;
  while(n--){
    cin >> x >> y >> d >> g;
    board[x][y] = 1;
    for(auto dragon: dc[g]){
      dragon = (dragon + d) % 4;
      if(dragon == 0) board[++x][y] = 1;
      if(dragon == 1) board[x][--y] = 1;
      if(dragon == 2) board[--x][y] = 1;
      if(dragon == 3) board[x][++y] = 1;
    }
  }
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) result += 1;
  cout << result;
}
