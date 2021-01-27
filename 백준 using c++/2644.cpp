//2644: 촌수계산
#include <bits/stdc++.h>
using namespace std;
bool people[101];
int relation[101][101];
int cnt[101];

int main(){
  int n,parents, child,r,r1,r2;
  cin >> n >> parents >> child >> r;
  for(int i = 0; i < r; i++){
    cin >> r1 >> r2;
    relation[r1][r2] = 1;
    relation[r2][r1] = 1;
  }
  queue<int> q;
  q.push(parents);
  people[parents] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i = 1; i <= n; i++){
      if(people[i] == 0 && relation[cur][i]== 1){
        if(i == child){
          cout << cnt[cur]+1;
          return 0;
        }
        q.push(i);
        people[i] = 1;
        cnt[i] = cnt[cur]+1;
      }
    }
  }
  cout << -1;
  return 0;
}
