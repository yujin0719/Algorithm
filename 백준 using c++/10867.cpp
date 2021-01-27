// 10867: 중복 빼고 정렬하기

#include <bits/stdc++.h>
using namespace std;
int n;
int num[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num,num+n);
  int tmp = 0;
  for(int i = 0; i < n; i++){
    if(num[i] == tmp) continue;
    cout << num[i] << " ";
    tmp = num[i];
  }
}         
