// leve1 이상한 문자 만들기

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 2 ;
    for(auto a : s){
        if(a == ' ') {
            answer += a;
            idx = 2;
        }
        else {
            if(idx%2==0) answer += toupper(a);
            else answer += tolower(a);
            idx += 1;
        }
    }
    return answer;
}
