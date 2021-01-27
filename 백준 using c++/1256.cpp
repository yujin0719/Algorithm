// 1256: 사전
// 참고) https://github.com/encrypted-def/BOJ/blob/master/1256.cpp

#include <bits/stdc++.h>
using namespace std;
int comb[205][205];
int n,m,k;
string result = "";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= 200; i++){
    comb[i][0] = comb[i][i] = 1;
    for(int j = 1; j < i; j++){
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
      if(comb[i][j] > 1e9+1) comb[i][j] = 1e9+1;
    }
  }
  if(comb[n+m][n] < k){
    cout << -1;
    return 0;
  }
  int len = n+m;
  while(len--){
    if(!n){
      result += "z";
      m--;
      continue;
    }
    if(!m){
      result += "a";
      n--;
      continue;
    }
    if(comb[n+m-1][n-1] >= k){
      result += "a";
      n--;
    }
    else{
      result += "z";
      k -= comb[n+m-1][n-1];
      m--;
    }
  }
  cout << result;
}         
