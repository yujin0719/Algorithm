//level2  기능개발

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> temp;
    for(int i = 0; i < progresses.size(); i++)
        temp.push_back((100-progresses[i])%speeds[i] == 0? (100-progresses[i])/speeds[i]:(100-progresses[i])/speeds[i]+1);

    int cur = temp[0];
    int cnt = 0;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i]>cur){
            answer.push_back(cnt);
            cnt = 1;
            cur = temp[i];
        }
        else cnt ++;
    }
    answer.push_back(cnt);
    return answer;
}
