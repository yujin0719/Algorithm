// 15898: 피아의 아틀리에 ~신비한 대회의 연금술사~
// BackTracking으로 방향은 잡았지만 역시 구현에서 너무 어려웠다.
// 다른 블로그를 많이 참고했다.

#include <bits/stdc++.h>
using namespace std;
struct state {
  int num;
  char color;
  state() { }
  state(int _num,char _color) : num(_num),color(_color) { }
};

int n,result = 0;
int efficent[10][4][4][4];
char element[10][4][4][4];
bool choice[10];
vector<vector<state>> board(5,vector<state>(5));

// 회전하는 함수
void rotate (int type, int dir){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      efficent[type][dir][i][j] = efficent[type][dir-1][3-j][i];
      element[type][dir][i][j] = element[type][dir-1][3-j][i];
    }
  }
}
// 품질 반환
int getQuailty(vector<vector<state>> v){
  int r = 0, b = 0, g = 0, y = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(v[i][j].color == 'R') r += v[i][j].num;
      if(v[i][j].color == 'B') b += v[i][j].num;
      if(v[i][j].color == 'G') g += v[i][j].num;
      if(v[i][j].color == 'Y') y += v[i][j].num;
    }
  }
  return (7*r)+(5*b)+(3*g)+(2*y);
}

// 시작점을 정해서 배치
vector<vector<state>> material(vector<vector<state>> v, int row, int col, int type, int dir){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      v[row+i][col+j].num += efficent[type][dir][i][j];
      if(v[row+i][col+j].num < 0) v[row+i][col+j].num  = 0;
      if(v[row+i][col+j].num > 9) v[row+i][col+j].num = 9;
      if(element[type][dir][i][j] != 'W') v[row+i][col+j].color = element[type][dir][i][j];
    }
  }
  return v;
}

// 재료 3개 선택
void select(vector<vector<state>> v, int cnt){
  if(cnt == 3){
    result = max(result,getQuailty(v));
    return;
  }
  for(int i = 0; i < n; i++){
    if(!choice[i]){
      choice[i] = true;
      // 16가지의 배치: (0,0)(0,1)(1,0)(1,1) * 4방향 회전
      for(int row = 0; row <= 1; row++){
        for(int col = 0; col <= 1; col++){
          for(int dir = 0; dir < 4; dir++){
            vector<vector<state>> tmp = material(v,row,col,i,dir);
            select(tmp,cnt+1);
          }
        }
      }
      choice[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        cin >> efficent[i][0][j][k];
      }
    }
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        cin >> element[i][0][j][k];
      }
    }
    for(int dir = 1; dir < 4; dir ++)
      rotate(i,dir);
  }
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      board[i][j] = state(0,'W');

  select(board,0);
  cout << result;
}
