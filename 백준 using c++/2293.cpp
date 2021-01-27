// 2293: 동전1

#include <bits/stdc++.h>
using namespace std;
int n,k;
int coin[10001];
vector<int> v1;
vector<int> v2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  v1.resize(k+1);
  v2.resize(k+1);
  for(int i = 0; i < n; i++) cin >> coin[i];
  for(int t = 0; t <= k; t += coin[0]) v1[t] = 1;
  for(int i = 1; i < n; i++){
   fill(v2.begin(),v2.end(),0);
   for(int j = 0; j <= k; j++){
     v2[j] = v1[j];
     if(j >= coin[i]) v2[j] += v2[j-coin[i]];
   }
   v1 = v2;
  }
  cout << v1[k];
}
