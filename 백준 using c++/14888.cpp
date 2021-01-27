// 14888: 연산자 끼워넣기
#include <bits/stdc++.h>
using namespace std;
int n;
int number[101];
int oper[4];
int m=1e9,M=-1e9;

void DFS(int plus, int minus, int multiply, int divide, int cnt, int result){
  if(cnt == n) {
    m = min(m,result);
    M = max(M,result);
  }
  if(plus > 0) DFS(plus-1,minus, multiply,divide,cnt+1,result+number[cnt]);
  if(minus > 0) DFS(plus,minus-1, multiply,divide,cnt+1,result-number[cnt]);
  if(multiply > 0) DFS(plus,minus, multiply-1,divide,cnt+1,result*number[cnt]);
  if(divide > 0) DFS(plus,minus, multiply,divide-1,cnt+1,result/number[cnt]);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> number[i];
  for(int i = 0; i < 4; i++)
    cin >> oper[i];
  DFS(oper[0],oper[1],oper[2],oper[3],1,number[0]);
  cout << M << "\n" << m;
  return 0;
}
