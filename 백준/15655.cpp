// 15655 : N과M(6)

#include <bits/stdc++.h>
using namespace std;
int N,M;
int input[9];

void func(int *arr,int num,int k){
  if(k==M){
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = num; i < N; i++){
    arr[k] = input[i];
    func(arr,i+1,k+1);
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
  func(result,0,0);
}
