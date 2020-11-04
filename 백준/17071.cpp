// 17071: 숨바꼭질 5
#include <bits/stdc++.h>
using namespace std;
int dist[2][500001];
int n,k;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  fill(dist[0],dist[0]+500001,-1);
  fill(dist[1],dist[1]+500001,-1);
  dist[0][n] = 0;
  queue<pair<int,int>> q;
  q.push({0,n});
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(auto nxt: {cur.second-1,cur.second+1,2*cur.second}){
      if(nxt >= 0 and nxt <= 500000 and dist[1-cur.first][nxt] == -1){
        dist[1-cur.first][nxt] = dist[cur.first][cur.second] + 1;
        q.push({1-cur.first,nxt});
      }
    }
  }
  int result = 0x7f7f7f7;
  int tmp = 0;
  while(k <= 500000){
    if(dist[tmp%2][k] != -1 and dist[tmp%2][k] <= tmp) result = min(result,tmp);
    tmp ++;
    k += tmp;
  }
  if(result == 0x7f7f7f7) result = -1;
  cout << result;
  return 0;
}
