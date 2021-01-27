// 6359: 만취한 상범

#include <bits/stdc++.h>
using namespace std;
int t, n;
int divisor(int n){
  int result = 0;
  for(int i = 2; i <= n; i++){
    if(n % i == 0) result += 1;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	cin >> t;
  while(t--){
    cin >> n;
    int answer = 0;
    for(int i = 2; i <= n; i++){
      if(divisor(i) % 2 == 0) answer += 1;
    }
    cout << answer+1 <<'\n';
  }
}
