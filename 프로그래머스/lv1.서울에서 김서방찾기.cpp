// leve1 서울에서 김서방찾기
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            answer += to_string(i);
            break;
        }
    }
    answer += "에 있다";
    return answer;
}
