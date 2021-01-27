// 15651 : N과 M(3)

#include <bits/stdc++.h>
using namespace std;
int N,M;

void func(int *arr,int k){
  if(k==M){
    for(int i = 0; i < M; i++)
      cout << arr[i]+1 << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < N; i++){
      arr[k] = i;
      func(arr,k+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int arr[M] = {};
  func(arr,0);
}
