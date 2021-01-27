// 완전탐색 > 모의고사

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rule1[5] = {1,2,3,4,5};
int rule2[8] = {2,1,2,3,2,4,2,5};
int rule3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int stu[3] = {0,};
    for(int i = 0; i < answers.size(); i++){
        if(rule1[i%5] == answers[i])
            stu[0]++;
        if(rule2[i%8] == answers[i])
            stu[1]++;
        if(rule3[i%10] == answers[i])
            stu[2]++;
    }
    int answer_max = max(max(stu[0],stu[1]),stu[2]);
    for(int i = 0; i < 3; i ++ ){
        if(answer_max == stu[i])
            answer.push_back(i+1);
    }

    return answer;
}
