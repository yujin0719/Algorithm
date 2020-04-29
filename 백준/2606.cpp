//2606: 바이러스
#include <bits/stdc++.h>
using namespace std;
int pai[101][101];
int vis[101];

int main(){
  int N,p,cnt=0;
  cin >> N >> p;
  while(p--){
    int temp1,temp2;
    cin >> temp1 >> temp2;
    pai[temp1][temp2] = 1;
    pai[temp2][temp1] = 1;
  }
  queue<int> q;
  q.push(1);
  vis[q.front()]=1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i = 1; i <= N; i++){
      if(pai[cur][i]==1 && vis[i]!=1){
        q.push(i);
        vis[i] = 1;
        cnt++;
      }
    }
  }
cout << cnt;
return 0;
}
