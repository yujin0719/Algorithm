// Level1: 예산

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    int total = 0;
    for(int i = 0; i < d.size(); i++){
        if(total + d[i] > budget) return answer;
        total += d[i];
        answer += 1;
    }
    return answer;
}
