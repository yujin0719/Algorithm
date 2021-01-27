// 1764: 듣보잡

#include <bits/stdc++.h>
using namespace std;
int N,M;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  vector<string> v,result;
  while(N--){
    string tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(),v.end());
  while(M--){
    string tmp;
    cin >> tmp;
    if(binary_search(v.begin(), v.end(), tmp)) result.push_back(tmp);
  }
  sort(result.begin(),result.end());
  cout << result.size() << "\n";
  for(auto t : result) cout << t << "\n";
}
