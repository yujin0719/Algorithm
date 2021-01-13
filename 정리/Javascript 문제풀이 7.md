# 프로그래머스 문제풀이 - JavaScript Level2
### 1. 124 나라의 숫자
    function solution(n) {
        return n ? solution(parseInt((n - 1) / 3)) + [1,2,4][(n - 1) % 3] : '';
    }
    
### 2. 가장 큰 정사각형 찾기

### 3. 올바른 괄호
    function solution(s){
        let cnt = 0;
        for(let i = 0; i < s.length; i++){
            if(s[i] === '(')
                cnt += 1;
            else if(cnt > 0)
                cnt -= 1;
            else
                return false;
        }
        return cnt ? false : true;
    }
    
### 4. 다음 큰 숫자
    function solution(n) {
        const bin_num = n.toString(2).match(/1/g).length;
        while(true){
            n ++;
            if(n.toString(2).match(/1/g).length === bin_num) return n;
        }
    }

### 5. 땅따먹기
    function solution(land) {
        return Math.max(...land.reduce((a, c, i) => {
            return [
                c[0] + Math.max(a[1], a[2], a[3]),  
                c[1] + Math.max(a[0], a[2], a[3]),
                c[2] + Math.max(a[0], a[1], a[3]),
                c[3] + Math.max(a[0], a[1], a[2]),
            ];
        }, [0, 0, 0, 0]));
    }
    
- 조금 더 이해하기 쉬운 방법

        function solution(land) {
            for(let i = land.length - 2; i >= 0; i--){
                land[i][0] = Math.max(land[i+1][1],land[i+1][2],land[i+1][3]) + land[i][0];
                land[i][1] = Math.max(land[i+1][0],land[i+1][2],land[i+1][3]) + land[i][1];
                land[i][2] = Math.max(land[i+1][0],land[i+1][1],land[i+1][3]) + land[i][2];
                land[i][3] = Math.max(land[i+1][0],land[i+1][1],land[i+1][2]) + land[i][3];
            }
            return Math.max(...land[0]);

        }
        
### 6. 숫자의 표현
    function solution(n) {
        var answer = 0;
        let arr = [];
        let total = 0;
        for(let i = 1; i <= n; i++){
            arr.push(i);
            total += i;
            while(total > n){
                total -= arr.shift();
            }
            if(total === n){
                answer += 1;
                total -= arr.shift();
            }
        }
        return answer;
    }

### 7. 최댓값과 최솟값
    function solution(s) {
        let arr = s.split(' ').map(v => parseInt(v));
        return [Math.min(...arr),Math.max(...arr)].join(" ");
    }
    
