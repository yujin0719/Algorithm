// 1476: 날짜 계산

#include <bits/stdc++.h>
using namespace std;
int E,S,M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	cin >> E >> S >> M;
  for(int i = 1; i <= 7980; i++){
    if(E == 15) E = 0;
    if(S == 28) S = 0;
    if(M == 19) M = 0;
    if(i % 15 == E && i % 28 == S && i % 19 == M){
      cout << i ;
      return 0;
    }
  }
}
