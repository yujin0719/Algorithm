// 16987: 계란으로 계란치기

#include <bits/stdc++.h>
using namespace std;
int N;
int s[8],w[8],vis[8];
int result,cnt;

int combination(int start){
  // 가장 오른쪽의 계란까지 손에 들고 난뒤 몇개가 깨졌는지 계산
  if(start == N){
    cnt = 0;
    for(int k = 0; k < N; k++){
      if(s[k] <= 0 ) cnt ++;
    }
    return cnt;
  }
  // 손에 들고 있는 계란이 이미 깨진 상태
  if(s[start] <= 0) return combination(start+1);
  bool check = false; // 무언가를 깼는지 확인하는 변수
  for(int i = 0; i < N; i++){
    if(i == start) continue;
    if(s[i] <= 0) continue;
    // i번째 계란을 깨기
    check = true;
    s[start] = s[start]-w[i];
    s[i] = s[i] - w[start];
    result = max(result,combination(start+1));
    s[start] = s[start]+w[i];
    s[i] = s[i] + w[start];

  }
  // 아무것도 깰수 없었으면 다음 계란을 손에 든다.
  if(!check) return combination(start+1);
  return result;
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> s[i];
    cin >> w[i];
  }
  result = 0;
  cout << combination(0);
  return 0;
}
