// 무지의 먹방 라이브

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    long long total = 0;
    for(int i = 0; i < food_times.size(); i++) total += food_times[i];
    if(total <= k) return -1;

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < food_times.size(); i++) pq.push({-food_times[i],i+1});

    total = 0;
    long long previous = 0;
    long long left = food_times.size();

    while(total+((-pq.top().first-previous)*left) <= k){
        int now = -pq.top().first;
        pq.pop();
        total += (now - previous) * left;
        left -= 1; // 다 먹은 음식
        previous = now;
    }

    vector<pair<int,int>> result;
    while(!pq.empty()){
        int time =  -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        result.push_back({time,idx});
    }
    sort(result.begin(),result.end(),compare);
    return result[(k-total)%left].second;
}
