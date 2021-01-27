// 1145: 적어도 대부분의 배수
#include <bits/stdc++.h>
using namespace std;
int num[5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	for(int i = 0; i < 5; i++) cin >> num[i];
  int result = 1;
  while(true){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
      if(result % num[i] == 0) cnt +=1;
    }
    if(cnt >= 3){
      cout << result;
      return 0;
    }
    result += 1;
  }
}
