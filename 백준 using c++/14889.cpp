// 14889: 스타트와 링크

#include <bits/stdc++.h>
using namespace std;
int n,mini = 0xfffffff;
int stats[21][21];
int team[21];

void stat_calc(){
  vector<int> start,link;
  int sum1 = 0,sum2 = 0;
  for(int i = 0; i < n; i++){
    if(team[i] == 1) start.push_back(i);
    if(team[i] == 2) link.push_back(i);
  }
  for(int i = 0; i < n/2; i++){
    for(int j = 0; j < n/2; j++){
      sum1 += stats[start[i]][start[j]];
      sum2 += stats[link[i]][link[j]];
    }
  }
  mini = min(mini,abs(sum1-sum2));
}

void split(int s,int l,int idx){
  if(idx == n){
    stat_calc();
    return;
  }
  if(s > 0){
    team[idx] = 1;
    split(s-1,l,idx+1);
    team[idx] = 0;
  }
  if(l > 0){
    team[idx] = 2;
    split(s,l-1,idx+1);
    team[idx] = 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> stats[i][j];

  split(n/2,n/2,0);
  cout << mini;
}
