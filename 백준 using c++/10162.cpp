// 10162: 전자레인지
#include <bits/stdc++.h>
using namespace std;
int t;
int cnt[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  if(t / 300 > 0) {
    cnt[0] += (t/300);
    t %= 300;
  }
  if(t / 60 > 0) {
    cnt[1] += (t/60);
    t %= 60;
  }
  if(t / 10 > 0) {
    cnt[2] += (t/10);
    t %= 10;
  }
  if(t == 0){
    for(int i = 0; i < 3; i++)
      cout << cnt[i] << " ";
  }
  else cout << -1;
}         
