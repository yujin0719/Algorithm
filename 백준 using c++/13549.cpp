// 13549 숨바꼭질3

// 순간이동하는 경우는 시간이 0이기 때문에 먼저 queue 에 넣어줘야 한다. 이것 때문에 엄청 헤맸다 ㅠㅠ

#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
int vis[100001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,K;
  cin >> N >> K;
  queue<int> q;
  q.push(N);
  vis[N] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(cur == K) {
      cout << cnt[cur];
      return 0;
    }
    if(cur*2 >=0 && cur*2 <= 100000 && vis[cur*2] == 0) {
      q.push(cur*2);
      vis[cur*2] = 1;
      cnt[cur*2] = cnt[cur];
    }
    if(cur-1 >=0 && cur-1 <= 100000 && vis[cur-1] == 0) {
      q.push(cur-1);
      vis[cur-1] = 1;
      cnt[cur-1] = cnt[cur] +1 ;;
    }
    if(cur+1 >=0 && cur+1 <= 100000 && vis[cur+1] == 0) {
      q.push(cur+1);
      vis[cur+1] = 1;
      cnt[cur+1] = cnt[cur] +1 ;
    }
  }
  return 0;
}
