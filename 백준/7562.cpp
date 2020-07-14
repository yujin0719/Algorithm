//7562 나이트의 이동
// 이 문제는 어렵지는 않았지만, break와 continue를 잘 구별해서 사용해야한다. 

#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};
int board[301][301];
int vis[301][301];
int T;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){
    int l,total = 0;
    cin >> l;
    queue<pair<int,int> > q;
    int s1,s2,d1,d2;
    bool flag = false;

    for(int i = 0 ; i < l; i++)
      fill(vis[i],vis[i]+l,0);

    cin >> s1 >> s2 >> d1 >> d2;
    if(s1 == d1 && s2 == d2){
      cout << 0 << "\n";
      continue;
    }
    q.push({s1,s2});
    while(!q.empty()){
      if(flag == true) break;
      auto cur = q.front();
      q.pop();
      for(int i = 0; i < 8; i++){
        if(cur.first+dx[i] == d1 && cur.second+dy[i] == d2){
          cout << vis[cur.first][cur.second]+1 << '\n';
          flag = true;
          break;
        }
        if(cur.first+dx[i] < 0 || cur.first+dx[i] >= l || cur.second+dy[i] < 0 || cur.second+dy[i] >= l) continue;
        if(vis[cur.first+dx[i]][cur.second+dy[i]] > 0) continue;
        q.push({cur.first+dx[i],cur.second+dy[i]});
        vis[cur.first+dx[i]][cur.second+dy[i]] = vis[cur.first][cur.second]+1;
      }
    }
  }
  return 0;
}
