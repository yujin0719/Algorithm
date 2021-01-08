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

- 문자열을 정수로 바꾸는 다른 방법 : **+s, s * 1, s / 1, parseInt(s)**

### 14. 시저 암호
    function solution(s, n) {
        var answer = '';
        for(let i = 0; i < s.length; i++){
            if(s[i] === ' ')
                answer += ' ';
            else 
                answer += String.fromCharCode((s.charCodeAt(i) > 90) ? (s.charCodeAt(i)+n-97)%26+97 : (s.charCodeAt(i)+n-65)%26+65);
        }
        return answer;
    }
- String.fromCharCode(): 유니코드를 입력으로 받아 **문자열**을 반환

- charCodeAt(idx): 입력된 index에 해당하는 **유니코드**를 반환

- charAt(idx): 입력된 index에 해당하는 **문자**를 반환

### 15. 약수의 합
    function solution(n) {
        return Array(n).fill().map((v, i) => i + 1).reduce((a, c) => n % c ? a : a + c, 0)
    }
- fill: 배열의 시작 인덱스부터 끝 인덱스의 이전까지 정적인 값 하나로 채우는 메소드
    - arr.fill(value[, start[, end]])
    
             const arr1 = [1, 2, 3, 4];
             console.log(arr1.fill(0, 2, 4)); // [1, 2, 0, 0]

- map: 배열 내의 모든 요소에 대하여 주어진 함수를 호출한 결과의 배열을 반환하는 메소드

    - arr.map(callback(currentValue[, index[, array]])[, thisArg])
    
            const arr1 = [1, 4, 9, 16];
            const map1 = arr1.map(x => x * 2);
            console.log(map1);  // [2, 8, 18, 32]


- reduce 
