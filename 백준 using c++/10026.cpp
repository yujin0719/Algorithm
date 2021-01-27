//10026: 적록색약
#include <bits/stdc++.h>
using namespace std;

char board[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char color[3] = {'R','B','G'};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> board[i];

  queue<pair<int,int> > q;
  int origin = 0;
  int error = 0;

  for(int k = 0; k < 3; k++){
    for(int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if(color[k] == board[i][j] && vis[i][j] == 0){
          origin +=1;
          q.push({i,j});
          vis[i][j] = 1;
          while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(int m = 0; m < 4; m ++){
              if(cur.first+dx[m] >= 0 && cur.second+dy[m] >= 0 && cur.first+dx[m] < N && cur.second+dy[m] < N){
                if(vis[cur.first+dx[m]][cur.second+dy[m]] == 0 && board[cur.first+dx[m]][cur.second+dy[m]] == color[k]){
                q.push({cur.first+dx[m],cur.second+dy[m]});
                vis[cur.first+dx[m]][cur.second+dy[m]] = 1;
                }
              }
            }
          }
        }
      }
    }
  }

  for(int i = 0; i < N; i++){
    fill(vis[i],vis[i]+N,0);
    for(int j = 0; j < N; j++){
      if(board[i][j] == 'G')
        board[i][j] = 'R';

    }
  }

  for(int k = 0; k < 2; k++){
    for(int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if(color[k] == board[i][j] && vis[i][j] == 0){
          error +=1;
          q.push({i,j});
          vis[i][j] = 1;
          while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(int m = 0; m < 4; m ++){
              if(cur.first+dx[m] >= 0 && cur.second+dy[m] >= 0 && cur.first+dx[m] < N && cur.second+dy[m] < N){
                if(vis[cur.first+dx[m]][cur.second+dy[m]] == 0 && board[cur.first+dx[m]][cur.second+dy[m]] == color[k]){
                q.push({cur.first+dx[m],cur.second+dy[m]});
                vis[cur.first+dx[m]][cur.second+dy[m]] = 1;
                }
              }
            }
          }
        }
      }
    }
  }
   cout << origin  << ' ' << error << '\n';
}
