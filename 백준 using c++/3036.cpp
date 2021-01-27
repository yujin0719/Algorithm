// 3036: 링
#include <bits/stdc++.h>
using namespace std;
int n;
int num[101];

int GCD(int a, int b){
  int answer = 1;
  for(int i = 2; i <= a; i++){
    if(a % i == 0 && b % i == 0)
      answer = i;
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  for(int i = 1; i < n; i++)
    cout << num[0] / GCD(num[0],num[i]) <<"/"<<num[i] / GCD(num[0],num[i]) <<"\n";
}         
