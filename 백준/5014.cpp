// 5014: 스타트링크
//주의해야할 요소: 같은층에서 같은층으로 이동할때는 use the stairs가 아니라 0을 출력해야한다!

#include <bits/stdc++.h>
using namespace std;
int stair[1000001];
bool vis[1000001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int F,S,G,U,D;
  cin >> F >> S >> G >> U >> D;

  queue<int> q;
  q.push(S);
  vis[S] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(cur == G){
      cout << stair[cur];
      return 0;
    }
    if(cur+U <= F && vis[cur+U]==0){
      vis[cur+U] = 1;
      q.push(cur+U);
      stair[cur+U] = stair[cur]+1;
    }
    if(cur-D >= 1 && vis[cur-D]==0){
      vis[cur-D] = 1;
      q.push(cur-D);
      stair[cur-D] = stair[cur]+1;
    }

}
  cout << "use the stairs";
  return 0;
}
