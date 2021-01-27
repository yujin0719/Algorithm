// 1463: 1로 만들기

// 1. BFS로 구현해보기

// #include <bits/stdc++.h>
// using namespace std;
// int n;
// int numbers[int(1e6)];
//
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   queue<int> q;
//   q.push(n);
//   while(!q.empty()){
//     auto cur = q.front();
//     q.pop();
//     if(cur == 1) {
//       cout << numbers[1];
//       break;
//     }
//     if(cur % 3 == 0 && numbers[cur/3] == 0){
//       q.push(cur/3);
//       numbers[cur/3] = numbers[cur]+1;
//     }
//     if(cur %2 ==0 && numbers[cur/2] == 0){
//       q.push(cur/2);
//       numbers[cur/2] = numbers[cur]+1;
//     }
//     if(cur - 1 >= 1 && numbers[cur-1] == 0){
//       q.push(cur-1);
//       numbers[cur-1] = numbers[cur]+1;
//     }
//   }
// }

// 2. DP로 구현해보기
#include <bits/stdc++.h>
using namespace std;
int n;
int numbers[int(1e6)];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  numbers[1] = 0;
  for(int i = 2; i <= n; i++){
    numbers[i] = numbers[i-1]+1;
    if(i%2 == 0) numbers[i] = min(numbers[i],numbers[i/2]+1);
    if(i%3 == 0) numbers[i] = min(numbers[i],numbers[i/3]+1);
  }
  cout << numbers[n];
}
