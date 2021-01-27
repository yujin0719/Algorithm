// 1253: 좋다

#include <bits/stdc++.h>
using namespace std;
int n,result = 0;
int a[2001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  for(int target = 0; target < n; target++){
    int left = 0, right = n-1;
    while(left < right){
      if(left == target) left++;
      if(right == target) right--;
      if(right == left) break;
      if(a[left] + a[right] == a[target]){
        result ++;
        break;
      }
      else if(a[left] + a[right] > a[target]) right --;
      else left ++;
    }
  }
  cout << result;
}         
