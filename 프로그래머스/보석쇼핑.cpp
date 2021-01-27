 // 2020 카카오 인턴쉽: 수식 최대화
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    int left = 0, right = 0, dist = gems.size()+1;
    map<string, int> m;
    for(string i : gems) {
        m[i] += 1;
    }
    int total = m.size();
    m.clear();
    while(true){
        if(m.size() == total) {
            if(right-left < dist){
                dist = right-left;
                answer[0] = left+1;
                answer[1] = right;
            }
            if(m[gems[left]] > 1) m[gems[left]] -= 1;
            else m.erase(gems[left]);
            left += 1;
        }
        else if(right == gems.size()) break;
        else if(m.size() < total) {
            m[gems[right]] += 1;
            right += 1;
        }
    }
    return answer;
}
