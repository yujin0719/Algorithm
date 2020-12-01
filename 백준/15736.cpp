// 15736: 청기 백기
#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int answer = 0;
  for(long long i = 1; i * i <=  n; i++) answer += 1;
  cout << answer;
}
