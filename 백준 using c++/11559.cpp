//11559: Puyo Puyo

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
bool flag = false;
string board[13];
bool bomb[13][7]; // 방문한 적 있는지 체크하는 배열
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void BFS(){
  queue<pair<int,int>> q; // BFS를 위한 queue
  while(true){
    vector<pair<int, int>> remove; // 제거해야할 블록을 모아둔 벡터
    for(int i = 0; i < 12; i++) fill(bomb[i],bomb[i]+6,0);
    for(int i = 0; i < 12; i++){
      for(int j = 0; j < 6; j++){
        if(board[i][j] == '.') continue;
        else if(!bomb[i][j]){
          char color = board[i][j];
          bomb[i][j] = 1;
          queue<pair<int,int>> popped; // 같은 색 + 인접한 블록
          q.push({i,j});
          while(!q.empty()){
            auto cur = q.front();
            q.pop();
            popped.push({cur.first,cur.second});
            for(int dir = 0; dir < 4; dir++){
              int nx = dx[dir] + cur.first;
              int ny = dy[dir] + cur.second;
              if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && board[nx][ny] == color && !bomb[nx][ny]){
                bomb[nx][ny] = 1;
                q.push({nx,ny});
              }
            }
          }
          if(popped.size() >= 4){  // 4개 이상의 같은 색이 인접하다면
            while(!popped.empty()){
              remove.push_back({popped.front().first,popped.front().second});
              popped.pop();
            }
          }
        }
      }
    }
    if(remove.size() > 0){
      sort(remove.begin(),remove.end());
      for(int i = 0; i < remove.size(); i++){
        for(int j = remove[i].first;  j > 0; j--)
          board[j][remove[i].second] = board[j - 1][remove[i].second];
         board[0][remove[i].second] = '.';
      }
      cnt ++;
    }
    else break;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 12; i++) cin >> board[i];
  BFS();
  cout << cnt;
}
