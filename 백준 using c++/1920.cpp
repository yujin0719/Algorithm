// 1920 수찾기
#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[100005];

bool binary(int num, int len){
  int start = 0;
  int end = len-1;
  while(start <= end){
    int mid = (start+end)/2;
    if(num < board[mid]) end = mid-1;
    else if(num > board[mid]) start = mid + 1;
    else return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> board[i];
  sort(board,board+n);
  cin >> m;
  for(int i = 0; i < m; i++){
    int num;
    cin >> num;
    if(binary(num,n)) cout << "1\n";
    else cout << "0\n";
  }
}
