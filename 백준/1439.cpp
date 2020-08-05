// 1439 : 뒤집기
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string tmp;
  cin >> tmp;
  int zero = 0;
  int one = 0;

  if(tmp[0] == '1') one ++;
  if(tmp[0] == '0') zero ++;
  for(int i = 1; i < tmp.size(); i++){
    if(tmp[i]!=tmp[i-1]){
      if(tmp[i] == '1') one++;
      if(tmp[i] == '0') zero++;
    }
  }
  if(zero > one) cout << one;
  else cout << zero;
  return 0;
}
