// level1: 3진법 뒤집기

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> s;
    while(n >= 1){
        s.push(n%3);
        // cout << n%3 << "\n";
        n /= 3;
    }
    int digit = 1;
    while(!s.empty()){
        answer += (digit * s.top());
        s.pop();
        digit *= 3;
    }
    return answer;

}
