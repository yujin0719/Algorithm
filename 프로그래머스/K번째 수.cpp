// 정렬 > k번째 수 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> temp;
        for(int j = 0; j < commands[i][1]-commands[i][0]+1; j++){
            temp.push_back(array[commands[i][0]+j-1]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}
