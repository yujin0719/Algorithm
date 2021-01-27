// 2206 벽 부수고 이동하기 --> 1600번 문제랑 비슷

#include <bits/stdc++.h>
using namespace std;
char board[1001][1001];
int dis[1001][1001][2];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N, M;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> board[i][j];
  queue<pair<pair<int,int>,pair<int,int>>> q;
  q.push({{0,0},{1,0}});
  dis[0][0][0] = 1;

  while(!q.empty()){
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    int dist = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if(curX == N-1 && curY == M-1){
      cout << dist;
      return 0;
    }
    for(int i = 0; i < 4; i++){
      if(curX+dx[i] >= 0 && curY+dy[i] >= 0 && curX+dx[i] < N && curY+dy[i] < M){
        // 벽이 아닌 경우
        if(dis[curX+dx[i]][curY+dy[i]][cnt] == 0 && board[curX+dx[i]][curY+dy[i]]== '0'){
          q.push({{curX+dx[i],curY+dy[i]},{dist+1,cnt}});
          dis[curX+dx[i]][curY+dy[i]][cnt] = 1;
          cout << "X: " << curX+dx[i] << " Y: " <<curY+dy[i] <<" dist: " << dist+1<<"\n";
        }
       // 벽이 있는데 벽을 부수지 않았던 경우
        else if(cnt == 0 && dis[curX+dx[i]][curY+dy[i]][cnt] == 0 && board[curX+dx[i]][curY+dy[i]] == '1'){
          q.push({{curX+dx[i],curY+dy[i]},{dist+1,cnt+1}});
          dis[curX+dx[i]][curY+dy[i]][cnt+1] = 1;
        }
      }
    }
  }
  cout << -1;
  return 0;
}
