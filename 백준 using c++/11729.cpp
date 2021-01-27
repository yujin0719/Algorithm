#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n){
  if(n==1){
    cout << a << " " << b << '\n';
    return ;
  }
  int c = 6 - a - b;
  hanoi(a,c,n-1);
  cout << a << " " << b << '\n';
  hanoi(c,b,n-1);
}

int main(void){
  int n;
  cin >> n;
  // or (1<<n)-1로 표현해도 된다.
  // pow는 double형 실수를 반환한다!
  cout << int(pow(2,n))-1 << '\n';
  hanoi(1,3,n);
}
