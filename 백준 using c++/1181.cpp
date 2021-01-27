// 1181: 단어 정렬
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> words;

bool comp(string a, string b){
  if(a.size()!= b.size()) return a.size() < b.size();
  return a < b;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++){
    string tmp;
    cin >> tmp;
    words.push_back(tmp);
  }
  stable_sort(words.begin(),words.end(), comp);
  for(int i = 0; i < n; i++) {
    if(i!=0 && words[i]==words[i-1]) continue;
    cout << words[i] <<'\n';
    }
}
