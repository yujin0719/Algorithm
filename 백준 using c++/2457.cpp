// 2457: 공주님의 정원
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i= 0; i< n; i++){
    pair<int,int> start,end;
    cin >> start.first >> start.second >> end.first >> end.second;
    v.push_back({start.first*100+start.second,end.first*100+end.second});
  }
  sort(v.begin(),v.end());
  int idx = -1, tmp = 0, result = 0;
  for(int i = 301; i <= 1130 && idx < n; i = tmp){
    bool flag = false;
    idx++;
    for(int j = idx; j < v.size(); j++){
      if(v[j].first > i) break;
      if(tmp < v[j].second){
        tmp = v[j].second;
        idx = j;
        flag = true;
      }
    }
    if(flag) result ++;
    else {
      cout << 0 << "\n";
      return 0;
    }
  }
  cout << result;
}         
