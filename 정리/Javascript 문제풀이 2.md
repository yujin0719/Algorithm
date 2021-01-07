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
  
  
### 7. 문자열 내 p와 y의 개수
    function solution(s) {
      const p = s.split('').filter(v => ['p', 'P'].includes(v));
      const y = s.split('').filter(v => ['y', 'Y'].includes(v));
      return p.length === y.length;
    }
    
- includes(): 배열이 특정 요소를 포함하는지 판별하는 메소드

        const arr = [1, 2, 3];
        console.log(arr.includes(2));  // true
  
### 8. 문자열 내림차순 배치하기
    function solution(s){
        return s.split('').sort().reverse().join('');
    }
    
### 9. 문자열 다루기 기본
    function solution(s) {
        if(s.length != 4 && s.length != 6){
            return false;
        }
        for(var i = 0; i < s.length; i++){
            if (!Number.isInteger(Number(s[i])))
                return false;
        }
        return true;
    }

### 10. 서울에서 김서방 찾기
    function solution(seoul) {
    return '김서방은 ' + seoul.indexOf('Kim') + '에 있다';
    }
