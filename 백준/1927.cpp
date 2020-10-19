// 1927: 최소힙
#include <bits/stdc++.h>
using namespace std;
int heap[100005];
int hs = 0;

void add(int x){
  hs+=1;
  heap[hs] = x;
  int idx = hs;
  while(idx != 1){
    int parent = idx/2;
    if(heap[parent] < heap[idx]) break;
    swap(heap[parent],heap[idx]);
    idx = parent;
  }
}

int top(){
  if(hs == 0) return 0;
  return heap[1];
}

void pop(){
  if(hs == 0) return;
  swap(heap[hs],heap[1]);
  hs -= 1;
  int idx = 1;
  while(2*idx <= hs){
    int left = idx*2;
    int right = idx*2+1;
    int child;
    if(heap[left] < heap[right] or right > hs) child = left;
    else child = right;
    if(heap[idx] < heap[child]) break;
    swap(heap[idx],heap[child]);
    idx = child;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    if(x==0){
      cout << top() << "\n";
      pop();
    }
    else add(x);
  }

}
