// 탐욕(Greedy) > 체육복

 /*  어렵지 않았지만 마지막 answer을 구하는 과정에서
     stu[i] == 1이라고 조건문을 설정해서 계속 틀렸다....
     쉬운 조건이지만 확실하게 체크하지 않으면 삽질하게 되는 것 같다 ㅠㅠ
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> stu(n,1);
    for(int i = 0; i < lost.size(); i++)
        stu[lost[i]-1] --;
    for(int i = 0; i < reserve.size(); i++)
        stu[reserve[i]-1] ++;
    for(int i = 0; i < n; i++){
        if(i < n-1 && stu[i] == 0 && stu[i+1] == 2){
            stu[i]++;
            stu[i+1]--;
            continue;
        }
        if(i > 0 && stu[i] == 0 && stu[i-1] == 2){
            stu[i]++;
            stu[i-1]--;
        }
    }
    for(int i = 0; i < n; i++){
        if(stu[i] >= 1)
            answer++;
    }
    return answer;
}
