// 14502: 연구소

#include <bits/stdc++.h>
using namespace std;

int n,m,result = 0;
int board[9][9];
int tmp[9][9];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// 바이러스 퍼뜨리기
void spread(int x,int y){
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
      if(tmp[nx][ny] == 0){
        tmp[nx][ny] = 2;
        spread(nx,ny);
      }
    }
  }
}

// 안전영역 구하기
int safe(){
  int area = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(tmp[i][j] == 0){
        area += 1;
      }
    }
  }
  return area;
}

// 빈칸 3개 선택하기
void select(int cnt) {
  if(cnt == 3){
    for(int i = 0; i < n; i ++)
      for(int j = 0; j < m; j++)
        tmp[i][j] = board[i][j];
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j++){
        if(tmp[i][j] == 2){
          spread(i,j);
        }
      }
    }
    result = max(result,safe());
    return;
  }
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 0){
        board[i][j] = 1;
        cnt += 1;
        select(cnt);
        board[i][j] = 0;
        cnt -= 1;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  select(0);
  cout << result;
}
