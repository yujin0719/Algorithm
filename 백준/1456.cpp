// 1456: 거의 소수
#include <bits/stdc++.h>
using namespace std;
long long a,b,answer = 0;
int prime[10000001];
vector<int> p;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;

  for(int i = 2; i < 10000001; i++){
    if(prime[i] == 1) continue;
    p.push_back(i);
    for(int j = i*2; j < 10000001; j += i) prime[j] = 1;
  }

  for(int i = 0; i < p.size(); i++){
    long long cur = p[i];
    long long tmp = cur;
    while(tmp <= b / cur){
      tmp *= cur;
      if(tmp >= a) answer += 1;
    }
  }
  cout << answer;
}
