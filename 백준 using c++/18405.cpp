// 18405: 경쟁적 전염
// compare 함수 내림차순 오름차순 헷갈려서 계속 헤맸다 ㅠㅠ

#include <bits/stdc++.h>
using namespace std;
int n,k,s,x,y;
int virus[201][201];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  return a.second < b.second;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<pair<pair<int,int>,int>> v;
  queue<pair<pair<int,int>,int>> q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> virus[i][j];
      if(virus[i][j] > 0) v.push_back({{i,j},virus[i][j]});
    }
  }
  sort(v.begin(),v.end(),compare);
  for(int i = 0; i < v.size(); i++)
    q.push({{v[i].first.first,v[i].first.second},0});
  cin >> s >> x >> y;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    if(cur.second == s) break;
    for(int i = 0; i < 4; i++){
      int nx = cur.first.first+dx[i];
      int ny = cur.first.second+dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < n && virus[nx][ny] == 0){
        virus[nx][ny] = virus[cur.first.first][cur.first.second];
        q.push({{nx,ny},cur.second+1});
      }
    }
  }
  cout << virus[x-1][y-1];
}
