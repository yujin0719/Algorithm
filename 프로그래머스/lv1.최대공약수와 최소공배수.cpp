lv1. 최대공약수와 최소공배수

#include <string>
#include <vector>

using namespace std;
// 유클리드 호제법
vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n, b = m;
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    answer.push_back(a);
    int lcm = a*(n/a)*(m/a);
    answer.push_back(lcm);
    return answer;
}
