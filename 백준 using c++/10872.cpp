//10872: 팩토리얼
// 쉬운문제이지만 num이 0인 경우를 고려하지 않으면 시간 초과가 나온다. 
#include <bits/stdc++.h>
using namespace std;

long long fact(int num){
  if(num == 1)
    return 1;
  else
    return num*fact(num-1);
}

int main(){
  int N;
  long long result = 1;
  cin >> N;
  if(N==0)
    cout << 1;
  else{
    result = fact(N);
    cout << result;
  }
  return 0;
}
