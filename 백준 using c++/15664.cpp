// 15664: N과 M(10)

#include <bits/stdc++.h>
using namespace std;
int N,M;
int num[10];
int seque[10];
bool check[10];

void recursion(int k){
  if(k == M){
    for(int i = 0; i < M; i++)
      cout << seque[i] << " ";
    cout << "\n";
    return;
  }
  int before = -1;
  for(int i = 0; i < N; i++){
    if(!check[i] && num[i] != before && num[i] >= seque[k-1]){
      before = num[i];
      seque[k] = num[i];
      check[i] = 1;
      recursion(k+1);
      check[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> num[i];
  sort(num,num+N);
  recursion(0);
}
