// 13335: 트럭

#include <bits/stdc++.h>
using namespace std;
queue<int> bridge;
int n,w,l;
queue<int> train;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> w;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    train.push(tmp);
  }
  for(int i = 0; i < l; i ++) bridge.push(0);
  int total = 0, present =0;
  while(true){
    if(train.size()==0) break;
    total += 1;
    present -= bridge.front();
    bridge.pop();
    if(present+train.front() <= w){
      bridge.push(train.front());
      present+=train.front();
      train.pop();
    }
    else{
      bridge.push(0);
    }
  }
  cout << total+l;
  return 0;
}
