// 11047: 동전 0
#include <bits/stdc++.h>
using namespace std;
int n,k;
int coin[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> coin[i];
  int idx = n-1, result = 0;
  while(k > 0 && idx >= 0){
    if(k - coin[idx] >= 0){
      k -= coin[idx];
      result += 1;
    }
    else idx -= 1;
  }
  cout << result;
}
