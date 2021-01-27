// 1449 : 수리공항승

#include <bits/stdc++.h>
using namespace std;
int vis[1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,L,cnt = 0;
  cin >> N >> L;
  int data[N];
  for(int i = 0; i < N; i++)
    cin >> data[i];
  sort(data,data+N);
  for(int i = 0; i < N; i++){
    if(vis[data[i]]==0){
      cnt ++;
      for(int j = data[i]; j < data[i]+L; j++){
        if(j <= 1001){
         vis[j] = 1;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}
