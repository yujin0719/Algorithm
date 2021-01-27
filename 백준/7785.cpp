// 7785: 회사에 있는 사람

#include <bits/stdc++.h>
using namespace std;
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  set<string> s;
  while(n--){
    string tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    if(!tmp2.compare("enter")) s.insert(tmp1);
    else s.erase(tmp1);
  }
  for (auto it = s.rbegin(); it != s.rend(); it++)
    cout << *it << "\n";

}
