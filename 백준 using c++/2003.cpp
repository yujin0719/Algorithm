// 2003: 수들의 합2
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  int result = 0,sum = 0;
  int right = 0, left = 0;
  while(left <= right && right <= n + 1){
    if(sum == m){
      sum -= a[left];
      left += 1;
      result +=1 ;
    }
    else if(sum > m){
      sum -= a[left];
      left += 1;
    }
    else {
      sum += a[right];
      right += 1;
    }
  }
  cout << result;
}
