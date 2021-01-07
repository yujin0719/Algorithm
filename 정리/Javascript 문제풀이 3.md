# 프로그래머스 문제풀이 - JavaScript Level1

### 11. 소수 찾기
    function solution(n) {
      const primes = new Array(n).fill(true);
      primes[0] = false;
      for(let i = 2; i **2 <= n; i++){
          if (primes[i-1] === true){
              for(let j = i**2; j <= n; j += i){
                  primes[j-1] = false;
              }
          }
      }
      return primes.filter((e) => e).length;
    }
    
### 12.수박수박수박수박수박수?
    function solution(n) {
      return '수박'.repeat(n).substr(0,n);
    }
    
- repeat: 문자열을 주어진 횟수만큼 반복해 붙인 새로운 문자열을 반환

      str.repeat(count);

### 13. 문자열을 정수로 바꾸기
    function solution(s) {
      return Number(s);
    }
