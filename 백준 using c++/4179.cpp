//4189.불

// 시작점이 두 종류일때 BFS로 해결
#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int distM[1002][1002];
int distF[1002][1002];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int R, C;
  queue<pair<int,int>> man;
  queue<pair<int,int>> fire;

  cin >> R >> C;
  for(int i = 0; i < R; i++){
    fill(distM[i],distM[i]+C,-1);
    fill(distF[i],distF[i]+C,-1);
  }
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      cin >> board[i][j];
      if(board[i][j] == 'J'){
        distM[i][j] = 0;
        man.push({i,j});
      }
      if(board[i][j] == 'F'){
        distF[i][j] = 0;
        fire.push({i,j});
      }
    }
  }
   while(!fire.empty()){
    auto cur = fire.front();
    fire.pop();
    for(int i = 0; i < 4; i++){
      if(cur.first+dx[i]>=0 && cur.second+dy[i]>=0 && cur.first+dx[i]< R && cur.second+dy[i] < C){
        if(distF[cur.first+dx[i]][cur.second+dy[i]] == -1 && board[cur.first+dx[i]][cur.second+dy[i]] != '#' ){
          fire.push({cur.first+dx[i],cur.second+dy[i]});
          distF[cur.first+dx[i]][cur.second+dy[i]] = distF[cur.first][cur.second]+1;
        }
      }
    }
  }
  while(!man.empty()){
    auto cur = man.front();
    man.pop();
    for(int i = 0; i < 4; i++){
      if(cur.first+dx[i] < 0 || cur.second+dy[i] < 0 || cur.first+dx[i] >= R || cur.second+dy[i] >= C){
        cout << distM[cur.first][cur.second]+1;
        return 0;
      }
      if(board[cur.first+dx[i]][cur.second+dy[i]] != '#' && distM[cur.first+dx[i]][cur.second+dy[i]] == -1){
        if(distF[cur.first+dx[i]][cur.second+dy[i]] == -1 || distF[cur.first+dx[i]][cur.second+dy[i]] > distM[cur.first][cur.second]+1){
          man.push({cur.first+dx[i],cur.second+dy[i]});
          distM[cur.first+dx[i]][cur.second+dy[i]] = distM[cur.first][cur.second]+1;
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
