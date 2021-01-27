// 1600: 말이 되고픈 원숭이

#include <bits/stdc++.h>
using namespace std;
int dh[4] = {1,-1,0,0};
int dw[4] = {0,0,1,-1};
int hh[8] = {1,1,-1,-1,2,2,-2,-2};
int hw[8] = {2,-2,2,-2,1,-1,1,-1};
int K,W,H;
int board[200][200];
int vis[200][200][32];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> W >> H;

  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      cin >> board[i][j];

  queue<pair<pair<int,int>,pair<int,int>>> q;
  q.push({{0,0},{0,0}});
  vis[0][0][0] = 1;

  while(!q.empty()){
    int curH = q.front().first.first;
    int curW = q.front().first.second;
    int horse = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if(curH == H-1 && curW == W-1){
      cout << cnt;
      return 0;
    }

    if(horse < K){
      for(int i = 0; i < 8; i++ ){
        int h = curH + hh[i];
        int w = curW + hw[i];
        if(h >= 0 && w >= 0 && h < H && w < W) {
          if(vis[h][w][horse+1] == 0 && board[h][w] == 0){
            vis[h][w][horse+1] = 1;
            q.push({{h,w},{horse+1,cnt+1}});
          }
        }
      }
    }
     for(int i = 0; i < 4; i++){
         int h = curH + dh[i];
         int w = curW + dw[i];
         if(h >= 0 && w >= 0 && h < H && w < W) {
             if(vis[h][w][horse] == 0 && board[h][w] == 0){
                 vis[h][w][horse] = 1;
                 q.push({{h,w},{horse,cnt+1}});
             }
         }
     }
  }
  cout << -1;
  return 0;
}
