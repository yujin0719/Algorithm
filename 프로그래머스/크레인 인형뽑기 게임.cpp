// 2019 카카오 개발자 겨울 인턴십 > 크레인 인형뽑기 게임

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    for(int i = 0; i < moves.size(); i++){
        int check = moves[i]-1;
        for(int j = 0; j < board.size(); j ++){
            if(board[j][check] != 0){
                if(!basket.empty() && board[j][check] == basket.back()){
                    basket.pop_back();
                    answer += 2;
                }
                else
                    basket.push_back(board[i][check]);
                board[j][check] = 0;
                break;
            }
        }
    }
    return answer;
}
