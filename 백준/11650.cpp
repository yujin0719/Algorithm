// 11650: 좌표 정렬하기

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> coordinate;

bool comp(pair<int,int> a, pair<int,int> b){
  if(a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    coordinate.push_back({x,y});
  }
  stable_sort(coordinate.begin(),coordinate.end(), comp);
  for(int i = 0; i < n; i++) {
    cout << coordinate[i].first << " " << coordinate[i].second << "\n";
  }
}
