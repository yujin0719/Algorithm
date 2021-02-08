//level1 문자열 내 p와 y의 개수

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int nump = 0;
    int numy = 0;

    for(int i = 0; i < s.size(); i++)
        if(s[i] < 95) s[i] = s[i]+32;

    for(int i = 0 ; i < s.size(); i ++){
        if(s[i] == 'p') nump ++;
        else if(s[i] == 'y') numy ++;
    }
    if(nump!= numy) answer = false;
    return answer;
}
