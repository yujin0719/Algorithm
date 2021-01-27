// 11967: 불켜기
#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
bool vis[101][101];
bool light[101][101];
vector<pair<int,int>> v[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  queue<pair<int,int>> q;
  while(m--){
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    v[x][y].push_back({a,b});
  }
  vis[1][1] = 1;
  light[1][1] = 1;
  q.push({1,1});
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(auto nxt : v[cur.first][cur.second]){
      if(vis[nxt.first][nxt.second]) continue;
      for(int i = 0; i < 4; i++){
        int nx = nxt.first + dx[i];
        int ny = nxt.second + dy[i];
        if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
        if(vis[nx][ny]){
          vis[nxt.first][nxt.second] = 1;
          q.push({nxt.first,nxt.second});
          break;
        }
      }
      light[nxt.first][nxt.second] = 1;
    }
    for(int i = 0; i < 4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
      if(!light[nx][ny] or vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cnt += light[i][j];
  cout << cnt;
}
