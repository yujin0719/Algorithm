// 13913: 숨바꼭질 4

#include <bits/stdc++.h>
using namespace std;
int position[100001];
int before[100001];
int subin,sibling;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> subin >> sibling;
  queue<int> q;
  q.push(subin);
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    if(cur == sibling){
      cout << position[cur] << '\n';
      vector<int> result;
      int tmp = before[cur];
      result.push_back(cur);
      for(int i = 0; i < position[cur]; i++){
        result.push_back(tmp);
        tmp = before[tmp];
      }
      for(int i = position[cur]; i >= 0; i--){
        cout << result[i] << " ";
      }
      return 0;
    }
    for(auto next: {cur-1,cur+1,cur*2}){
      if(next >= 0 && next <= 100000 && position[next] == 0){
        before[next] = cur;
        position[next] = position[cur]+1;
        q.push(next);
      }
    }
  }
}
