// 7453: 합이 0인 네 정수
#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0;
int a[4001],b[4001],c[4001],d[4001];
int mid1[16000001], mid2[16000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      mid1[i*n + j] = a[i] + b[j];
      mid2[i*n + j] = c[i] + d[j];
    }
  }
  sort(mid2,mid2+(n*n));
  for(int i = 0; i < n*n; i++)
    cnt += (upper_bound(mid2, mid2 + n * n, -mid1[i]) - lower_bound(mid2, mid2 + n * n, -mid1[i]));

  cout << cnt;
}
