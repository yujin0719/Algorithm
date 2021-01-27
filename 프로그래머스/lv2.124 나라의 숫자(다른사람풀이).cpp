// level2 124 나라의 숫자
// "412"[div] 사용하는 것 참고해보기

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int div;
    while(n > 0){
        div = n % 3;
        n = n / 3;
        if(div == 0) n -= 1;
        answer = "412"[div] + answer;
    }
    return answer;
}
