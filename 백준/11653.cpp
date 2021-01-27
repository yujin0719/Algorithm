// 11653: 소인수분해

#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int prime = 2;
  while(n > 1){
    if(n % prime == 0) {
      cout << prime << "\n";
      n /= prime;
    }
    else prime+=1;
  }
}
