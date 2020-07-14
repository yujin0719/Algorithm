//lv2.탑

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int,int>> s;
    for(int i = 0; i < heights.size(); i++){
        while(!s.empty()){
            if(s.top().second > heights[i]){
                answer.push_back(s.top().first);
                break;
            }
            s.pop();
        }
        if(s.empty())
            answer.push_back(0);
        s.push(make_pair(i+1,heights[i]));
    }


    return answer;
}
