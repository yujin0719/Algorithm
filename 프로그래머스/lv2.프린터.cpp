// level2. 프린터

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(i,priorities[i]));
    }

    while(!q.empty()){
        if(q.front().second == pq.top()){
            pq.pop();
            answer ++;
            if(q.front().first == location)
                break;
            q.pop();
        }
        else{
            q.push(make_pair(q.front().first,q.front().second));
            q.pop();
        }
    }
    return answer;
}
