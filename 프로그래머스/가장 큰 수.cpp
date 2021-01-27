// 가장 큰 수

#include <bits/stdc++.h>

using namespace std;
bool comp(string n1, string n2){
    return n1 + n2 > n2 + n1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(auto num : numbers) nums.push_back(to_string(num));
    sort(nums.begin(),nums.end(),comp);
    if (nums[0] == "0") return "0";
    for(auto n : nums) answer += n;
    return answer;
}
