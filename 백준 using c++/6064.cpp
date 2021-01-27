// 6064: 카잉 달력

#include <bits/stdc++.h>
using namespace std;
int t,m,n,x,y;
int modular(int m,int n, int x, int y){
  if(x == m) x = 0;
  if(y == n) y = 0;
  for(int i = x; i <= m*n; i+= m)
    if(i % n == y) return i;
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> m >> n >> x >> y;
    cout << modular(m,n,x,y) << '\n';
  }
}
