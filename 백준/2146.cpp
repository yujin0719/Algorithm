// 2146: 다리만들기

#include <bits/stdc++.h>
using namespace std;
int n;
int board[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void island(){
  bool vis[n][n];
  for(int i = 0; i < n; i++) fill(vis[i],vis[i]+n,false);
  int island_number = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j] or board[i][j] == 0) continue;
      queue<pair<int,int> > Q;
      Q.push({i,j});
      vis[i][j] = true;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        board[cur.first][cur.second] = island_number;
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.first+dx[dir];
          int ny = cur.second+dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny] || board[nx][ny] == 0) continue;
          Q.push({nx,ny});
          vis[nx][ny] = true;
        }
      }
      island_number ++ ;
    }
  }
}

int min_dist(int x, int y){
  int dist[n][n];
  for(int i = 0; i < n; i++) fill(dist[i],dist[i]+n,-1);
  queue<pair<int,int> > Q;
  Q.push({x,y});
  dist[x][y] = 0;
  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();
    for(int i = 0 ; i < 4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] >= 0) continue;
      if(board[nx][ny] == board[x][y]) continue;
      if(board[nx][ny] != 0)
        return dist[cur.first][cur.second];
      dist[nx][ny] = dist[cur.first][cur.second]+1;
      Q.push({nx,ny});
    }
  }
  return 99999;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];
  island();
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j++){
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  int result = 0xffffff;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 0) continue;
      result = min(result, min_dist(i,j));
    }
  }
  cout << result;
}
