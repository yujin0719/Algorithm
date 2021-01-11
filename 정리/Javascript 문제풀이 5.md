# 프로그래머스 문제풀이 - JavaScript Level1

### 21. 제일 작은 수 제거하기
    function solution(arr) {
      const m = Math.min(...arr);
      var answer = arr.filter((e) => e != m);
      return answer.length == 0 ? [-1] : answer;
    }
### 22. 짝수와 홀수
    function solution(num) {
        return num % 2 == 0 ? "Even" : "Odd";
    }
### 23. 최대공약수와 최소공배수
    function solution(n, m) {
        function GCD(a,b){
            return b == 0 ? a : GCD(b,a%b);
        }
        var gcd = GCD(n,m);
        return [gcd,n*m/gcd];
    }
### 24. 콜라츠 추측
    function solution(num) {
        var answer = 0;
        while(num != 1){
            num = num % 2 === 0 ? num / 2 : num * 3 + 1;
            answer += 1;
            if(answer > 500) return -1;
        }
        return answer;
    }
### 25. 평균 구하기
    function solution(arr) {
        var answer = arr.reduce((a,c) => a+c);
        return answer / arr.length;
    }
