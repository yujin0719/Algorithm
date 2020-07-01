// level1. 시저암호

 // else if 문에 a <= 90 , a >= 97조건을 넣지 않아서 한참을 해맸다.
 // 넣지 않으면 s: xxXy	n:23	result : uuUv 이 테스트케이스에서 답이 나오지 않는다.
 
 // 그래서 저렇게 조건문으로 하는 것보다 %26을 사용하는게 더 낫다....


#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto a : s){
        if(a == ' ') answer += a;
        else if((a <= 90 && a+n >= 65 && a+n <= 90)||(a >= 97 && a+n >= 97 && a+n <= 122)) answer += a+n;
        else answer += (a+n-26);
    }
    return answer;
}
