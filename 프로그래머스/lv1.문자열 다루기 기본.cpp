//level1 문자열 다루기 기본
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() != 4 && s.size() != 6) answer = false;
    for(auto c:s){
        if(!isdigit(c)){
            answer = false;
            break;
        }
    }
    return answer;
}
