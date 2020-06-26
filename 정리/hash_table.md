# Hash Table (해쉬테이블)

> 해쉬테이블은 검색하고자하는 key를 입력받아 hash돌려서 반환받을 hash code를 배열의 index로 환산해 데이터에 접근하는 방식의 자료구조이다. 
Function(key) -> Hash Code -> Index -> Value

- 장점 : 검색속도가 매우 빠르다 / O(1)에서 최대 O(n)
- collison 충돌
  - different keys(문자열이므로 다양) -> same code (정수)
  - different codes -> same index(배열) 
- 대부분 Hash 문제는 정렬로 해결할 수 있다. 하지만 정렬은 O(nlgn)의 시간복잡도를 가지므로 Hash에 대해 알아두는 것이 좋다.

- ex1) 완주하지 못한 선수(프로그래머스)

     <strong>문제 설명</strong>
      
      수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
      마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

     <strong>제한사항</strong>
      
      마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
      completion의 길이는 participant의 길이보다 1 작습니다.
      참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
      참가자 중에는 동명이인이 있을 수 있습니다.
      
     <strong>코드</strong>
      
      #include <string>
      #include <vector>
      #include <unordered_map>
      
      using namespace std;
      stirng solution(vector<string> participant, vector<string> completion){
        stirng answer = "";
        unordered_map<string,int> h;
        for(auto name : completion){
          if(h.end() == h.find(name))    // 찾는게 없으면 end()값을 반환한다. 
            h.insert(make_pair(name,1));
          else h[name]++;
        }
        for(auto name : participant){
          if(h.end() == h.find(name)){
            answer = name;
            break;
          }
          else{
            h[name]--;
            if(h[name] < 0){
              answer = name;
              break;
            }
          }
        }
        return answer;
      }
      
- ex2) 완주하지 못한 선수(프로그래머스)

     <strong>문제 설명</strong>
     
      전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
      전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

      구조대 : 119
      박준영 : 97 674 223
      지영석 : 11 9552 4421
      전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.
