//1182: 부분수열의 합

#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,S;
  cin >> N >> S;

  int count = 0;
  for(int i = 0; i < N; i++) cin >> a[i];
  for(int i = 1; i < (1<<N); i++){
    int total = 0;
    int tmp = i;
    for(int j = 0; j < N; j++){
      if(tmp % 2 == 1)
        total += a[j];
      tmp /= 2;
    }
    if(total == S ) count ++;
  }
  cout << count;
  return 0;
}
