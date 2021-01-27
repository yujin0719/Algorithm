// 2501: 약수 구하기
#include <bits/stdc++.h>
using namespace std;
int n ,k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<int> v;
  for(int i = 1; i*i <= n; i++)
    if(n % i == 0) v.push_back(i);
  for(int i = v.size()-1; i >= 0; i--){
    if(v[i]*v[i] == n) continue;
    v.push_back(n/v[i]);
  }
  if(k <= v.size()) cout << v[k-1];
  else cout << 0;
}
