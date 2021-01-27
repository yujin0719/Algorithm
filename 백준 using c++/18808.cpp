// 18808 스티커 붙이기

#include <bits/stdc++.h>
using namespace std;
int n,m,k,r,c;
int note[42][42];
int paper[12][12];

void rotate(){
  int tmp[12][12];
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      tmp[i][j] = paper[i][j];
  for(int i = 0; i < c; i++)
    for(int  j= 0; j < r; j++)
      paper[i][j] = tmp[r-1-j][i];
  swap(r,c);
}

bool postable(int x, int y){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(note[x+i][y+j] == 1 && paper[i][j] == 1)
      return false;
    }
  }
  return true;
}

void post(int x, int y){
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if(paper[i][j] == 1)
        note[x+i][y+j] = 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;

  while(k--){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cin >> paper[i][j];

    for(int i = 0; i < 4; i++){
      bool is_post = false;
      for(int x = 0; x <= n-r; x++){
        if(is_post) break;
        for(int y = 0; y <= m-c; y++){
          if(postable(x,y)){
            post(x,y);
            is_post = true;
            break;
          }
        }
      }
      if(is_post) break;
      rotate();
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cnt += note[i][j];
  cout << cnt;
  return 0;
}
