// 11050: 이항 계수 1
#include <bits/stdc++.h>
using namespace std;
int n,k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int result = 1;
  for(int i = 0; i < k; i++)
    result *= (n-i);
  for(int i = 1; i <= k; i++)
    result /= i;
  cout << result;
}
