//18406: 럭키 스트레이트
#include <bits/stdc++.h>
using namespace std;
string N;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int len = N.size();
  int total = 0;
  for(int i = 0; i < len/2; i++)
    total += int(N[i]);
  for(int i = len/2; i<len;i++)
    total -= int(N[i]);

  if(total == 0)
    cout << "LUCKY";
  else
    cout << "READY";
  return 0;
}
