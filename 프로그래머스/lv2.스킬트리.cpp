//lv2 스킬트리

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        string com = skill_trees[i];
        int check = 0;
        bool flag = true;

        for(int j = 0; j < com.size(); j++){
            int nDeli = skill.find(com[j]);
            if(nDeli < 0 || nDeli > 30) continue;
            else if(nDeli != check){
                flag = false;
                break;
            }
            else check ++;
        }
        if(flag) answer ++;
    }
    return answer;
}
