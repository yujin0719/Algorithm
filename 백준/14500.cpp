// 14500: 테트로미노

#include <bits/stdc++.h>
using namespace std;
int n,m;
int result = 0;
int board[501][501];
bool vis[501][501];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void DFS(int x, int y, int cnt,int sum){
  if(cnt == 4){
    result = max(result,sum);
    return;
  }
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (vis[nx][ny] == true) continue;
    vis[nx][ny] = true;
    DFS(nx,ny,cnt+1,sum+board[nx][ny]);
    vis[nx][ny] = false;
  }
}

void except(int x,int y){
  if(x+1 < n && y+2 < m)
    result = max(result,(board[x][y]+board[x][y+1]+board[x][y+2]+board[x+1][y+1]));
  if(x+2 < n && y+1 < m)
    result = max(result,(board[x][y]+board[x+1][y]+board[x+2][y]+board[x+1][y+1]));
  if(x-1 >= 0 && y-2 >= 0)
    result = max(result,(board[x][y]+board[x][y-1]+board[x][y-2]+board[x-1][y-1]));
  if(x-2 >= 0 && y-1 >= 0)
    result = max(result,(board[x][y]+board[x-1][y]+board[x-2][y]+board[x-1][y-1]));
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0 ; j < m; j++)
      cin >> board[i][j];
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < m; j++){
      fill(vis[i],vis[i]+m,false);
      DFS(i,j,0,0);
      except(i,j);
    }
  }
  cout << result;
}
