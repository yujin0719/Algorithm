//level1 자릿수 더하기

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while(n > 0){
        answer += (n%10);
        n = n/10;
    }
    return answer;
}

// (s[i] - '0') 이렇게 하면 숫자로 바뀔수 있다는 것도 알아두자.
