// 1019: 책페이지

#include <bits/stdc++.h>
using namespace std;
long long n,digit = 1;
long long num[10];

void calc(long long n){
  while(n != 0){
    num[n%10] += digit;
    n /= 10;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long first = 1;
  while(first <= n){
    while(first % 10 != 0 && first <= n){
      calc(first);
      first ++;
    }
    if(first > n) break;
    while(n % 10 != 9 && first <= n){
      calc(n);
      n--;
    }
    first /= 10;
    n /= 10;
    for(int i = 0; i < 10; i++) num[i] += (n-first+1)*digit;
    digit *= 10;
  }
  for(int i = 0; i < 10; i++) cout << num[i] << " ";
}         
