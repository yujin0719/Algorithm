// 5904: moo 게임
#include <bits/stdc++.h>
using namespace std;
int n;
long long D[150]; // 글자수

char s(int n){
  if(n==1) return 'm';
  if(n==2 || n==3) return 'o';
  int i = 0;
  while(D[i] < n) i++;
  if(D[i] == n) return 'o';
  if(n - D[i-1] == 1) return 'm';
  if(n - D[i - 1] <= i + 3) return 'o';
	return s(n - D[i - 1] - (i + 3));
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  D[0] = 3;
  for(int i = 1; i < 40; i++) D[i] = D[i-1]*2 + (i+3);
  cout << s(n);
}
