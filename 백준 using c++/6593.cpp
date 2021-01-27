// 6593: 상범빌딩
// 10번이상 틀렸습니다를 받았던 문제다..
// vis를 초기화하는 방법이 잘못되었던 것 같다.

#include <bits/stdc++.h>
using namespace std;
int l,r,c;
string building[31][31];
int vis[31][31][31];
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};

void BFS(){
  queue<tuple<int,int,int>> q;
  tuple<int,int,int> exit;
  for(int i = 0; i < l; i++){
    for(int j = 0; j < r; j++){
      cin >> building[i][j];
      for(int k = 0; k < c; k++){
        if(building[i][j][k] == 'S') {
          q.push({i,j,k});
          vis[i][j][k] = 0;
          }
        if(building[i][j][k] == 'E') {
          get<0>(exit) = i;
          get<1>(exit) = j;
          get<2>(exit) = k;
        }
      }
    }
  }
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    if(exit == cur){
      cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] << " minute(s).\n";
      return;
    }
    for(int i = 0; i < 6; i++){
      int nx = get<0>(cur)+dx[i];
      int ny = get<1>(cur)+dy[i];
      int nz = get<2>(cur)+dz[i];
      if(nx >= 0 && nx < l && ny >= 0 && ny < r && nz >= 0 && nz < c && vis[nx][ny][nz] == 0 && (building[nx][ny][nz] == '.'||building[nx][ny][nz] == 'E')){
        q.push({nx,ny,nz});
        vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
      }
    }
  }
  cout << "Trapped!\n";
  return;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(true){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0) return 0;
    for(int i = 0; i < l; i++){
      for(int j = 0; j< r; j++)
        fill(vis[i][j],vis[i][j]+c,0);
    }
    BFS();
  }
}
