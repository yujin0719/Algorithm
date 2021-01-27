//level1. 두 정수 사이의 합
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a == b) answer = a;
    else if(a > b){
        for(int i = b; i < a+1; i++)
            answer += i;
    }
    else{
        for(int i = a; i < b+1; i++)
            answer += i;
    }
    return answer;
}
