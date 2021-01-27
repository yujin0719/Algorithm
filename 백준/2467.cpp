// 2467: 용액

#include <bits/stdc++.h>
using namespace std;
int n;
long long num[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  long long num1 = num[0], num2 = num[n-1],gap = abs(num1+num2); // 초기화
  int right = n-1, left = 0; // index
  while(right > left){
    if(gap > abs(num[right]+num[left])){
      gap = abs(num[right]+num[left]);
      num1 = num[left];
      num2 = num[right];
    }
    if(num[right]+num[left] < 0) left ++;
    else right--;
  }
  cout << num1 << " " << num2;
}         
