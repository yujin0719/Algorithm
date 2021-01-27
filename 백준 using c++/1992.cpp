// 1992 쿼드트리
// 1780 종이의 개수와 유사한 유형이다. 

#include <bits/stdc++.h>
using namespace std;
char board[65][65];
int N;
vector<char> result;

void recursion(int x, int y, int s){
  char basic = board[y][x];
  if(s == 1){
    result.push_back(basic);
    return ;
  }
  for(int i = y; i < y+s; i++){
    for(int j = x; j < x+s; j++){
      if(board[i][j] != basic){
        result.push_back('(');
        for(int k = y; k < y+s; k+= s/2)
          for(int l = x; l < x+s; l+= s/2)
            recursion(l,k,s/2);
        result.push_back(')');
        return ;
      }
    }
  }
  result.push_back(basic);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> board[i];
  recursion(0,0,N);
  for(int i = 0; i < result.size(); i++)
    cout << result[i];
  return 0;
}
