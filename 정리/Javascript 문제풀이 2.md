# 프로그래머스 문제풀이 - JavaScript Level1
### 6. 문자열 내 마음대로 정렬하기
    function solution(strings, n) {
      return strings.sort((a,b) => {
          if(a[n] === b[n]){
              return (a > b) - (a < b);
          }
          return (a[n] > b[n]) - (a[n] < b[n]);
      });
    }
    
- localeCompare: 사전 순 정렬할 때 사용하는 메소드

      referenceStr.localeCompare(compareString[, locales[, options]])
      
  - 음수: referenceStr < compareStr 
  
  - 양수: referenceStr > compareStr
  
  - 0: referenceStr = compareStr
      
        var items = ['réservé', 'premier', 'cliché', 'communiqué', 'café', 'adieu'];
        items.sort((a, b) => a.localeCompare(b)); // ['adieu', 'café', 'cliché', 'communiqué', 'premier', 'réservé']
  
  
