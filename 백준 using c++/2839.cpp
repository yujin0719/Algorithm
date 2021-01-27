// 2839: 설탕 배달
#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	cin >> n;
  int tmp = n;
  int result = 0;
  while(tmp - 5 >= 0){
    tmp -= 5;
    result += 1;
  }
  while(tmp <= n){
    if(tmp == 0){
      cout << result;
      return 0;
    }
    if(tmp % 3 == 0){
      result += (tmp/3);
      tmp = 0;
    }
    else{
      tmp += 5;
      result -= 1;
    }
  }
  cout << -1;
}
