# 프로그래머스 문제풀이 - JavaScript Level1
### 16. 이상한 문자 만들기
    function solution(s) {
        var answer = '';
        answer = s.split(" ").map(arr => (arr.split("").map((e,i) => i % 2 == 0 ? e.toUpperCase() : e.toLowerCase()).join(""))).join(" ");
        return answer;
    }
    
### 17. 자릿수 더하기
    function solution(n){
        var answer = 0;
        const num = String(n);
        for(let i = 0; i < num.length; i++){
            answer += Number(num[i]);
        }
        return answer;
    }

### 18. 자연수 뒤집어 배열로 만들기
    function solution(n) {
        const num = String(n);
        return num.split("").map((e) => Number(e)).reverse();
    }

### 19. 정수 내림차순으로 배치하기
    function solution(n) {
        const num = String(n);
        return parseInt(num.split("").sort((a,b) => b-a).join(""));
    }
### 20. 정수 제곱근 판별
    function solution(n) {
        return Number.isInteger(Math.sqrt(n)) ? (Math.sqrt(n)+1)**2 : -1;
    }
