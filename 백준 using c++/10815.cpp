// 10815: 숫자 카드
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10000001];

bool binarySearch(int start, int end,int target){
  while(start <= end){
    int mid = (start+end) / 2;
    if(target == a[mid]) return true;
    else if(target > a[mid]) start = mid+1;
    else end = mid-1;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  cin >> m;
  for(int i = 0; i < m; i++){
    int target;
    cin >> target;
    if(binarySearch(0, n, target)) cout << "1 ";
    else cout << "0 ";
  }
} 
