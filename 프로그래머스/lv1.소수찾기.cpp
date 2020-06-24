//level1 소수찾기 
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n,true);
    for(int i = 2; i <= n; i++){
        if(prime[i] == false) continue;
        for(int j = i*2; j <= n; j+=i) prime[j] = false;
    }
    for(int i = 2; i <= n; i++)
        if(prime[i] == true) answer += 1;
    return answer;
}
