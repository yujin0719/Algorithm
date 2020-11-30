// 11051: 이항 계수 2
#include <bits/stdc++.h>
using namespace std;
int comb[1001][1001];
int n,k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= 1000; i++){
    comb[i][0] = comb[i][i] = 1;
    for(int j = 1; j < i; j++)
      comb[i][j] = (comb[i-1][j]+comb[i-1][j-1]) % 10007;
  }
  cout << comb[n][k];
}
