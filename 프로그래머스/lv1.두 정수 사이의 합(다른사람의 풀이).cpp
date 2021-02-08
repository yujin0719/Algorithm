// 문제 자체는 어렵지 않았지만 놓치기 쉬운 수학 개념으로 해결 할 수도 있었다.

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}
