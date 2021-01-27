// level1: 문자열 내 마음대로 정렬하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int idx;
bool comp(string str1, string str2){
    return str1[idx] == str2[idx] ? str1 < str2 : str1[idx] < str2[idx];
}
vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(),strings.end(),comp);
    return strings;
}
