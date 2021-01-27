// 1822: 차집합
#include <bits/stdc++.h>
using namespace std;
int na, nb;
int a[500001],b[500001];
vector<int> result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> na >> nb;
  for(int i = 0; i < na; i++) cin >> a[i];
  for(int i = 0; i < nb; i++) cin >> b[i];
  sort(b,b+nb);
  for(int i = 0; i < na; i++){
    if(!binary_search(b, b+nb, a[i])) result.push_back(a[i]);
  }
  if(result.size() == 0) cout << 0;
  else {
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
  }
}
