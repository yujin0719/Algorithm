#include <string>
#include <vector>
#include <stack>

using namespace std;
bool check(string p){
    stack<char> s;
    // true : 올바른 괄호 문자열
    for(auto c : p){
        if(c == '(') s.push(c);
        else if(!s.empty() && c == ')' && s.top() == '(') s.pop();
        else return false;
    }
    return true;
}

string parsing(string s){
    string result = "";
    if(s == "") return s;
    int open = 0;
    int close = 0;
    int index = 0;

    for(auto c : s){
        if(c == '(') open ++;
        else close ++;
        index ++;
        if(open == close) break;
    }
    string u = s.substr(0,index);
    string v = s.substr(index);
    if(check(u)) {
        result += u;
        result += parsing(v);
    }
    else{
        result += "(";
        result += parsing(v);
        result += ")";
        u = u.substr(1,u.size()-2);
        for(auto a : u){
            if(a == '(') result += ")";
            else result += "(";
        }
    }
    return result;
}

string solution(string p) {
    if(check(p)) return p;
    return parsing(p);
}
