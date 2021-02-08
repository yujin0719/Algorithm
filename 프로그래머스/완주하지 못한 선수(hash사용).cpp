// 해시 > 완주하지 못한 선수 (hash 활용해서 해결)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> h;
    for(auto name : completion){
      if(h.end() == h.find(name))
        h.insert(make_pair(name,1));
      else
        h[name]++;
    }

    for(auto name : participant){
      if(h.end() == h.find(name)){
        answer = name;
        break;
      }
      else {
        h[name]--;
        if(h[name] < 0) {
          answer = name;
          break;
        }
      }
    }
    return answer;
}
