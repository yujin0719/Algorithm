// 타켓 넘버

#include <bits/stdc++.h>
using namespace std;
int answer = 0;

void DFS(vector<int> n, int target, int cnt, int sum){
    if(cnt == n.size()-1){
        if(sum == target) answer++;
        return;
    }
    DFS(n,target,cnt+1,sum+n[cnt+1]);
    DFS(n,target,cnt+1,sum-n[cnt+1]);
}
int solution(vector<int> numbers, int target) {
    DFS(numbers,target,-1,0);
    return answer;
}
