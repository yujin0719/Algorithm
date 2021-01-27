// 해시 > 완주하지 못한 선수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    answer = participant.back();
    for(int i = 0; i < completion.size(); i++){
        if(participant[i].compare(completion[i])!=0){
            answer = participant[i];
            break;
        }
    }
    return answer;
}
