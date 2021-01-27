// 14921: 용액합성하기

// gap = min(abs(gap),abs(a[right]+a[left])); 이렇게 풀어서 계속 해맸다 ㅜㅜ
// 절대값이 아닌 차이를 출력해야하는 문제이다!!!

#include <bits/stdc++.h>
using namespace std;
int n,gap= 200000001;
int a[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int left = 0, right = n-1;
  while(left < right){
    gap = abs(gap) > abs(a[right]+a[left]) ? a[right]+a[left] : gap;
    if(a[right] + a[left] == 0) break;
    if(a[right] + a[left] > 0) right --;
    else left++;
  }
  cout << gap;
}
