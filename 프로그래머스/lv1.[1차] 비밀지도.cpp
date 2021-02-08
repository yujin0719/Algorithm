// Level1 : [1차] 비밀지도

#include <string>
#include <vector>
#include <iostream>

using namespace std;
string binary(int num, int n){
    string result = "";
    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(num % 2);
        num /= 2;
    }
    for(int i = n-1; i >= 0; i--) {
        result += to_string(v[i]);
    }
    return result;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        string tmp1 = binary(arr1[i],n);
        string tmp2 = binary(arr2[i],n);
        string tmp3 = "";
        for(int j = 0; j < n; j++){
            if(tmp1[j] == '0' && tmp2[j] == '0') tmp3 += " ";
            else tmp3 += "#";
        }
        answer.push_back(tmp3);
    }
    return answer;
}
