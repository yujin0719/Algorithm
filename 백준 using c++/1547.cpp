//1547: 공
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,result=1;
  cin >> N;
  for(int i = 0; i < N; i++){
    int num1,num2;
    cin >> num1 >> num2;
    if(num1 == result) result = num2;
    else if(num2 == result) result = num1;
  }
  cout << result;
  return 0;
}
