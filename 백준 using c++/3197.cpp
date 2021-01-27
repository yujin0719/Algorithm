// 3197:  백조의 호수

#include <bits/stdc++.h>
using namespace std;
int r,c;
vector<pair<int,int>> v;
string board[1501];
bool vis[1501][1501];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c ;
  queue<pair<int,int>> waterQ;
  for(int i = 0; i < r; i++){
    cin >> board[i];
    for(int j = 0; j < c; j++){
      if(board[i][j] == 'L') v.push_back({i,j});
      if(board[i][j] == '.' || board[i][j] == 'L') waterQ.push({i,j});
    }
  }
  queue<pair<int, int>> q;
  q.push({v[0].first,v[0].second});
  vis[v[0].first][v[0].second] = true;
  int day = 0;
  while(true){
    queue<pair<int,int>> nextQ;
    bool flag = false;
    while(!q.empty()){
      auto cur = q.front();
      q.pop();
      if(cur.first == v[1].first && cur.second == v[1].second){
        flag = true;
        break;
      }
      for(int i = 0; i < 4; i++){
        int nx = cur.first+dx[i];
        int ny = cur.second+dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && vis[nx][ny] == 0){
          vis[nx][ny] = true;
          if(board[nx][ny] == 'X') {
            nextQ.push({nx,ny});
            continue;
          }
          q.push({nx,ny});
        }
      }
    }
    if(flag) break;
      q = nextQ;
    int ws = waterQ.size();
    while(ws--){
      auto cur = waterQ.front();
      waterQ.pop();
       for(int i = 0; i < 4; i++){
        int nx = cur.first+dx[i];
        int ny = cur.second+dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == 'X'){
          board[nx][ny] = '.';
          waterQ.push({nx,ny});
        }
      }
    }
    day ++;
  }
  cout << day;
}
