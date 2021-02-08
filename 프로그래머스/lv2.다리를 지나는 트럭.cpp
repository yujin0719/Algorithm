// Level2: 다리를 지나는 트럭

#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for(int i = 0; i < bridge_length; i++) q.push(0);
    int w = 0, idx = 0;

    while(!q.empty()){
        answer ++;
        w -= q.front();
        q.pop();
        if(w + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            w += truck_weights[idx];
            idx ++;
            if(idx == truck_weights.size())
                return  answer + bridge_length;
        }
        else if (w + truck_weights[idx] > weight) {
            q.push(0);
        }
    }
}
