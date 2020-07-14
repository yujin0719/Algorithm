// 9466 텀프로젝트

// 이문제 진짜 오래걸렸다..
// 1. 다른 사람들로부터 지목을 받지 못한 인덱스를 큐에 넣는다.
// 2. 큐에서 하나씩 꺼내 가리키는 인덱스의 "지목받은 수" 를 -1 한다.
// 3. -1 한 수가 0이라면 해당 인덱스도 큐에 넣는다.
// 4. 반복

#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int selected[100002];
int T,n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){
    cin >> n;
    queue<int> q;
    int total = 0;
    fill(selected,selected+n+1,0);
    for(int i = 1; i <=n; i++){
      cin >> arr[i];
      selected[arr[i]] ++;
    }
    for(int i = 1; i <=n; i++)
      if(selected[i] == 0)
        q.push(i);

    while(!q.empty()){
      int cur = q.front();
      q.pop();
      total++;
      selected[arr[cur]] --;
      if(selected[arr[cur]] == 0)
        q.push(arr[cur]);
    }
    cout << total << '\n';
  }
  return 0;
}
