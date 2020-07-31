// 15654 : N과M(5)

#include <bits/stdc++.h>
using namespace std;
int N,M;
int input[9];

void func(int *arr,bool *used,int k){
  if(k==M){
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < N; i++){
    if(!used[i]){
      arr[k] = input[i];
      used[i] = 1;
      func(arr,used,k+1);
      used[i] = 0;
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; i++)
    cin >> input[i];
  sort(input,input+N);
  int result[M] = {};
  bool used[N] = {};
  func(result,used,0);
}
