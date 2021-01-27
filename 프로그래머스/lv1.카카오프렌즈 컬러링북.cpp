// level1. 카카오프렌즈 컬러링북

#include <vector>
#include <queue>

using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check[101][101];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i = 0; i < m; i ++)
        fill(check[i],check[i]+n,false);

    queue<pair<int,int> > q;

    for(int i = 0; i < m; i++){
        for(int  j = 0; j < n; j++){
            if(check[i][j] == false && picture[i][j] != 0){
                q.push({i,j});
                number_of_area += 1;
                check[i][j] = true;
                int area = 1;
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        if(cur.first+dx[k] >=0 && cur.second+dy[k] >=0 && cur.first+dx[k] < m && cur.second+dy[k] < n){
                            if(check[cur.first+dx[k]][cur.second+dy[k]] == false && picture[cur.first+dx[k]][cur.second+dy[k]] == picture[cur.first][cur.second]){
                                check[cur.first+dx[k]][cur.second+dy[k]] = true;
                                area++;
                                q.push({cur.first+dx[k],cur.second+dy[k]});
                            }
                        }
                    }
                }
                if(max_size_of_one_area < area)
                    max_size_of_one_area = area;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
