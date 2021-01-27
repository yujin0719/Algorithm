// 4796 : 캠핑
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt = 0;
  while(1){
    int L,P,V;
    cin >> L >> P >> V;
    cnt ++;
    if(L == 0 && P == 0 && V ==0)
      return 0;
    int day = (V/P)*L;
    if (V-(V/P)*P > L)
      day += L;
    else
      day += V - (V/P)*P;
    cout << "Case " << cnt << ": " << day << "\n";
  }
  return 0;
}
