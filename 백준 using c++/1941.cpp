// 1941: 소문난 칠공주
#include <bits/stdc++.h>
using namespace std;

#define MAX 5
#define TOTAL 7

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result;
string board[MAX];
bool visited[MAX][MAX];
bool checked[MAX][MAX];

// 2. 인접확인하기
void adjacency(int x, int y){
  for (int k = 0; k < 4; k++){
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
    // 방문한적이 없거나(7명에 속하지 않음) 인접확인을 한경우
    if(!visited[nx][ny] || checked[nx][ny]) continue;
    checked[nx][ny] = true;
    adjacency(nx,ny);
  }
}

// 1. 7명 뽑기 + 이다솜파가 4명 우위
void combination (int start, int s, int cnt){
    if(cnt - s >= 4) return;

    if(cnt == TOTAL && s >= 4){
      int check = 0;
      for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
          if(!visited[i][j] || checked[i][j]) continue;
          checked[i][j] = true;
          check ++;
          adjacency(i, j);
        }
      }
      for(int i = 0; i < 5; i++) fill(checked[i],checked[i]+5, 0);
      result = check == 1 ? result+1 : result;
      return;
    }

    for(int i = start; i < 25; i++){
      int x = i / 5;
      int y = i % 5;
      if(visited[x][y]) continue;
      visited[x][y] = true;
      combination(i,board[x][y]=='S'? s+1 : s, cnt+1);
      visited[x][y] = false;
    }
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++) cin >> board[i];
  combination(0,0,0);
  cout << result;
  return 0;
}
