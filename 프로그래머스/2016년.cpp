// 2016년

#include <string>
#include <vector>

using namespace std;
string week[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

string solution(int a, int b) {
    string answer = "";
    int sum = 0;
    if(a == 1) sum = (b+4)%7;
    else{
        for(int i = 0; i < a-1; i ++){
            sum += day[i];
        }
        sum = (sum+b+4)%7;
    }
    answer = week[sum];
    return answer;
}
