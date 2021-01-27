// 15663: N과 M(9)
#include <bits/stdc++.h>
using namespace std;
int N,M;
int num[10];
int arr[10];
bool isused[10];

void func(int k){
  if(k == M){
      for(int i = 0; i < M; i++)
        cout << arr[i] << ' ';
    cout << "\n";
    return;
  }
  int before = -1;
  for(int i = 0; i < N; i++){
    if(!isused[i] && (i == 0|| num[i]!=before)){
      before = num[i];
      arr[k] = num[i];
      isused[i] = 1;
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> num[i];
  sort(num,num+N);
  func(0);
}
