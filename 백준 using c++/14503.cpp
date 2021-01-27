//14503: 로봇청소기
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int area[51][51];
int main(){
  int N,M,r,c,d;
  cin >> N >> M >> r >> c >> d;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> area[i][j];
      // area == 0 청소하지 않은 공간
      // area == 1 벽
      // area == 2 청소한 공간
  int count = 0;
  while(true){
    // 2-1) 현재위치 청소하기
    if(area[r][c] == 0)
      area[r][c] = 2;
      // 2-3,2-4) 4방향 모두 청소가 되어 있거나 벽인 경우
    if(area[r+1][c] != 0 && area[r-1][c] != 0 && area[r][c-1] != 0 && area[r][c+1]){
      // 2-4) 뒤쪽 방향이 벽이라 후진을 할 수 없는 경우
      if(area[r-dx[d]][c-dy[d]] == 1) break;
      else{
        // 2-3) 한칸 후진하고 2번으로 돌아가기
        r -= dx[d];
        c -= dy[d];
      }
    }
    else{
      // 2-1, 2-2
      d = (d+3) % 4;
      // 2-1) 방향으로 회전해서 전진후 1진행
      if(area[r+dx[d]][c+dy[d]] == 0){
        r += dx[d];
        c += dy[d];
      }
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(area[i][j] == 2) count += 1;
    }
  }
  cout << count << '\n';
  return 0;
}
