// 1127: 로프
// 오름차순 정렬은  sort(numbers,numbers+n,greater<int>()); 이다
#include <bits/stdc++.h>
using namespace std;
int n;
int numbers[100000];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> numbers[i];
  int result = 0;
  sort(numbers,numbers+n);
  for(int i = n-1; i >= 0; i--){
    if(numbers[i]*(n-i) > result)
      result = numbers[i]*(n-i);
  }
  cout << result;
}
