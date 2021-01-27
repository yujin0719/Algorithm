// 5427: 불
#include <bits/stdc++.h>
using namespace std;
int t,w,h;
string board[1001];
int sang[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void BFS(){
  queue<pair<int,int>> fire;
  queue<pair<int,int>> man;
  for(int i = 0; i < h; i++) {
    cin >> board[i];
    for(int j = 0; j < w; j++){
      if(board[i][j] == '*') fire.push({i,j});
      if(board[i][j] == '@') man.push({i,j});
    }
  }
  while(true){
    // 불 옮기기
    queue<pair<int,int>> next;
    while(!fire.empty()){
      auto cur = fire.front();
      fire.pop();
      for(int i = 0; i < 4; i++ ){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w && (board[nx][ny] == '.' || board[nx][ny] == '@')){
          next.push({nx,ny});
          board[nx][ny] = '*';
        }
      }
    }
    fire = next;
    // 상근 이동
    queue<pair<int,int>> manNext;
    while(!man.empty()){
      auto cur = man.front();
      man.pop();
      for(int i = 0; i < 4; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
          cout << sang[cur.first][cur.second]+1 << "\n";
          return;
        }
        if(board[nx][ny] == '.' && sang[nx][ny] == 0){
          sang[nx][ny] = sang[cur.first][cur.second]+1;
          manNext.push({nx,ny});
        }
      }
    }
    if(manNext.empty()){
      cout << "IMPOSSIBLE\n";
      return;
    }
    man = manNext;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> w >> h;
    for(int i = 0; i < h; i++) fill(sang[i],sang[i]+w,0);
    BFS();
  }
}
