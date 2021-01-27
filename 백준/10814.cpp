//10814: 나이순 정렬
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,string>> man;

bool comp(pair<int,string> a, pair<int,string> b){
  return a.first < b.first;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++){
    int age;
    string name;
    cin >> age >> name;
    man.push_back({age,name});
  }
  stable_sort(man.begin(),man.end(), comp);
  for(int i = 0; i < n; i++) {
    cout << man[i].first << " " << man[i].second << "\n";
  }
}
