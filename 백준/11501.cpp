//11501: 주식

#include <bits/stdc++.h>
using namespace std;
int t,n;
int stock[1000001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> stock[i];
    int max = 0;
    long gain = 0;
    for(int i = n-1; i >=0 ; i--){
      if(stock[i] > max) max = stock[i];
      else gain += max - stock[i];
    }
    cout << gain << "\n";
  }

}
