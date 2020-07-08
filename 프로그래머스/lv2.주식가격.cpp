level2. 주식가격

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    for(int i = 0; i < prices.size(); i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        // i값을 넣어주는 것이 핵심이다.
        // 가격이 떨어지는 경우 즉, top가격이 더 높아서 stack에서 빠지는 경우 index를 어떻게 해야 할지 몰랐는데
        // i를 이용해서 s.top()을 인덱스로 활용하는 것이다.

        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = prices.size() - s.top() -1;
        s.pop();
    }
    return answer;
}
