//소수찾기
#include <bits/stdc++.h>
using namespace std;

bool vis[10000000];
bool selected[10];
int answer;

bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i==0) return false;
    return true;
}

void DFS(string s, string temp){
    if(temp != "" && !vis[stoi(temp)]){
        int num = stoi(temp);
        vis[num] = true;
        if(isPrime(num)) answer++;
    }
    for(int i = 0; i < s.length(); i++){
        if(selected[i]) continue;
        selected[i] = true;
        DFS(s,temp+s[i]);
        selected[i] = false;
    }
}

int solution(string numbers){
    DFS(numbers,"");
    return answer;
}
