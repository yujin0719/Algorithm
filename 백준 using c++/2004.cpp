// 2004: 조합 0의 개수
#include <bits/stdc++.h>
using namespace std;
int n,m;
int two,five;

int prime(int n1, int n2){
  int answer = 0;
  while(n1 > 0){
      n1 /= n2;
      answer += n1;
  }
  return answer;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  two = prime(n,2)-prime(m,2)-prime(n-m,2);
  five = prime(n,5)-prime(m,5)-prime(n-m,5);
  cout << min(two,five);
}         
