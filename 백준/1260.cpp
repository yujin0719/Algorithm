//1260: DFS와 BFS
#include <bits/stdc++.h>
using namespace std;
int arr[5001][5001];
bool vis[1001];
int m,n,v;

void DFS(int v){
  cout << v << ' ';
  vis[v] = 1;
  for(int i = 1; i <= m; i++){
    if(arr[v][i] == 1 && vis[i] == 0){
      DFS(i);
    }
  }
  return;
}

void BFS(int v){
  queue<int> q;
    q.push(v);
    vis[v] = 1;
    cout << v << ' ';
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(int i = 1; i <= m; i++){
        if(arr[cur][i]==1 && vis[i]==0){
          q.push(i);
          vis[i] = 1;
          cout << i << ' ';
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n >> v;

  int src, dest = 0;
  for(int i = 0; i < n; i++){
    cin >> src >> dest;
    arr[src][dest] = 1;
    arr[dest][src] = 1;
  }
  DFS(v);
  cout << '\n';
  for(int i = 1; i <= m; i++)
    vis[i] = false;
  BFS(v);
}
