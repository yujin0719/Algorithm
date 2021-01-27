// 7569.토마토
// 3차원 가로세로높이 행렬로 입력하는거 은근 헷갈린다 ㅠㅠ

#include <bits/stdc++.h>
using namespace std;
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {0,0,0,0,1,-1};
int dz[6] = {1,-1,0,0,0,0};
int board[101][101][101];
int vis[101][101][101];
int N,M,H;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<tuple<int,int,int>> q;
  cin >> M >> N >> H;
  int dist = 0,none=0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        cin >> board[j][k][i];
        if(board[j][k][i] == 1){
          q.push(make_tuple(j,k,i));
          vis[j][k][i] = 1;
        }
        if(board[j][k][i] == -1) none ++;
      }
    }
  }
  if(q.size() + none == N*M*H) {
    cout << 0;
    return 0;
  }
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 6; i++){
      int x =  get<1>(cur)+dx[i];
      int y = get<0>(cur)+dy[i];
      int z = get<2>(cur)+dz[i];
      if(x < 0 || y < 0 || z < 0 || x >= M || y >= N || z >= H) continue;
      if(board[y][x][z] == 0 && vis[y][x][z] == 0){
        q.push(make_tuple(y,x,z));
        board[y][x][z] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
      }
    }
  }
   for(int i = 0; i < H; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        if(board[j][k][i] == 0 && vis[j][k][i] == 0) {
          cout << -1;
          return 0;
        }
        if(board[j][k][i] > dist) dist = board[j][k][i];
      }
    }
   }
   cout << dist-1;
   return 0;
}
