// 15683 : 감시

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board1[10][10];
int board2[10][10];
vector<pair<int,int>> cctv;

// 범위 확인하기
bool boundary(int a, int b){
  return a < 0 || b < 0 || a >= N || b >= M;
}

// 사각지대 구하기 --> CCTV의 범위가 되는 곳을 7로 바꿈
// 여기서 dir은 cctv의 방향이다.
void blind (int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(boundary(x,y) || board2[x][y] == 6) return;
    if(board2[x][y] != 0) continue;
    board2[x][y] = 7;
  }
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int spot =0; // spot은 사각지대의 개수
   // 1. 입력받기
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board1[i][j];
      if(board1[i][j] != 0 && board1[i][j] != 6)
        cctv.push_back({i,j});
      if(board1[i][j] == 0) spot++;
    }
  }
  // 2. CCTV의 방향 설정하기
  for(int i = 0; i < 1<<(2*cctv.size()); i++){
    int tmp = i;
    // board2는 사각지대의 최소값을 구할때마다 reset해야한다.
    // 이것을 고려하지 않아서.. 오래걸렸다 ㅠㅠ
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
        board2[i][j] = board1[i][j];
    for(int j = 0; j < cctv.size(); j++){
      int brute = tmp % 4;
      tmp /= 4;
      int x = cctv[j].X;
      int y = cctv[j].Y;
      if(board1[x][y] == 1){
        blind(x,y,brute);
      }
      else if(board1[x][y] == 2){
        blind(x,y,brute);
        blind(x,y,brute+2);
      }
      else if(board1[x][y] == 3){
        blind(x,y,brute);
        blind(x,y,brute+1);
      }
      else if(board1[x][y] == 4){
        blind(x,y,brute);
        blind(x,y,brute+1);
        blind(x,y,brute+2);
      }
      else {
        blind(x,y,brute);
        blind(x,y,brute+1);
        blind(x,y,brute+2);
        blind(x,y,brute+3);
      }
    }
    // 3. 사각지대 크기 구하기
    int val = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
      val += (board2[i][j] == 0);

    spot = min(spot,val);
  }
  cout << spot;
  return 0;
}
