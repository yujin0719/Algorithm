// 10989: 수 정렬하기 3

#include <bits/stdc++.h>
using namespace std;
int n;
int num[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i  < n; i++){
    int tmp;
    cin >> tmp;
    num[tmp]++;
  }
  for(int i = 0; i  < 10001; i++){
    for(int j = 0; j < num[i]; j++){
      cout << i << "\n";
    }
  }
}
