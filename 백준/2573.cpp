//2574: 빙산

#include <bits/stdc++.h>
using namespace std;
int N,M;
int board[301][301];
int temp[301][301];
int visited[301][301];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> board[i][j];

  int year = 0;
  while(true){
    // 두개 이상으로 분리되었는지 확인
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++)
      fill(visited[i],visited[i]+M,0);

    int cnt = 0;
    for(int i = 1; i < N-1; i++){
      for(int j = 1; j < M-1; j++){
        if(board[i][j] > 0 && !visited[i][j]){
          cnt ++;
          if(cnt > 1) {
            cout << year;
            return 0;
          }
          q.push({i,j});
          visited[i][j] = 1;
          while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int k = 0; k < 4; k ++){
              int nx = dx[k] + cur.first;
              int ny = dy[k] + cur.second;
              if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
              if(board[nx][ny] > 0 && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
    // 1년뒤 바다, 빙하 모습
    year++;
    int ice = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        temp[i][j] = board[i][j];
        if(temp[i][j] > 0){
          for(int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == 0) temp[i][j] = temp[i][j]-1 >=0 ?temp[i][j]-1:0;
          }
        }
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        board[i][j] = temp[i][j];
        if(board[i][j] == 0) ice ++;
      }
    }

     // 빙하가 다 녹았는가?
     if(ice == N*M) {
       cout << 0;
       return 0;
     }
  }
}
