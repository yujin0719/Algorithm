// 더 맵게 (heap)
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto s : scoville) pq.push(s);
    while(true){
        if(pq.empty() || (pq.size() == 1 && pq.top() < K)) break;
        if(pq.top() >= K) return answer;
        answer += 1;
        int hot1 = pq.top();
        pq.pop();
        int hot2 = pq.top();
        pq.pop();
        pq.push(hot1+(hot2*2));
    }
    return -1;
}
