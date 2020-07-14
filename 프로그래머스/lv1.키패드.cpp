// level1. 키패드 누르기

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 12, left = 10;
    for(auto key : numbers){
        if(key == 0) key = 11;
        if(key % 3 == 1){
            left = key;
            answer.push_back('L');
        }
        else if(key % 3 == 0){
            right = key;
            answer.push_back('R');
        }
        else{
            // 거리계산
            int dis_r, dis_l;
            dis_r = (abs(right-key)+1)/3 + (right-2)%3;
            dis_l = (abs(left-key)+1)/3 + (left % 3)%2;

            if(dis_r > dis_l){
                left = key;
                answer.push_back('L');
            }
            else if(dis_r < dis_l){
                right = key;
                answer.push_back('R');
            }
            else {
                if(hand == "right"){
                    right = key;
                    answer.push_back('R');
                }
                else {
                    left = key;
                    answer.push_back('L');
                }
            }
        }
    }
    return answer;
}
