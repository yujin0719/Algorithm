//11449: 주사위 굴리기
#include <bits/stdc++.h>
using namespace std;
int die[7];
int ma[20][20];
int command[1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,k,x,y;

  cin >> N >> M >> x >> y >> k;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> ma[i][j];
  for(int i = 0; i < k; i++) cin >> command[i];

  for(int i = 0; i < k; i++){
    int nx = x+dx[command[i]-1];
    int ny = y+dy[command[i]-1];

    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
      continue;


    if(command[i] == 1){ // 동쪽이동
      int tmp = die[1];
      die[1] = die[4];
      die[4] = die[6];
      die[6] = die[3];
      die[3] = tmp;
    }
    else if(command[i] == 2){ // 서쪽이동
      int tmp = die[1];
      die[1] = die[3];
      die[3] = die[6];
      die[6] = die[4];
      die[4] = tmp;
    }
    else if(command[i] == 3){ // 북쪽이동
      int tmp = die[1];
      die[1] = die[5];
      die[5] = die[6];
      die[6] = die[2];
      die[2] = tmp;
    }
    else if(command[i] == 4){ // 남쪽이동
      int tmp = die[1];
      die[1] = die[2];
      die[2] = die[6];
      die[6] = die[5];
      die[5] = tmp;
    }
    x = nx;
    y = ny;
    if(ma[x][y] == 0)
      ma[x][y] = die[6];
    else{
      die[6] = ma[x][y];
      ma[x][y] = 0;
    }
    cout << die[1] << '\n';
  }
  return 0;
}
