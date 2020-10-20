// 10816: 숫자카드

#include <bits/stdc++.h>
using namespace std;
int n,m;
int numbers[500001];

int lower_idx(int target, int len){
  int start = 0;
  int end = len;
  while(start < end){
    int mid = (start+end)/2;
    if(numbers[mid] >= target) end = mid;
    else start = mid+1;
  }
  return start;
}
int upper_idx(int target, int len){
  int start = 0;
  int end = len;
  while(start < end){
    int mid = (start+end)/2;
    if(numbers[mid] > target) end = mid;
    else start = mid+1;
  }
  return end;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> numbers[i];
  sort(numbers,numbers+n);
  cin >> m;
  for(int i = 0; i < m; i++){
    int num;
    cin >> num;
    cout << upper_idx(num,n) - lower_idx(num,n) << " ";
  }
}
