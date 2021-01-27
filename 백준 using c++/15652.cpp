// 15652 : N과M(4)

#include <bits/stdc++.h>
using namespace std;
int N,M;

void func(int *arr,int num, int k){
  if(k==M){
    for(int i = 0; i < M; i++)
      cout << arr[i]+1 << ' ';
    cout << '\n';
    return;
  }

  for(int i = num; i < N; i++){
    arr[k] = i;
    func(arr,i,k+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int arr[M] ={};
  func(arr,0,0);
}
