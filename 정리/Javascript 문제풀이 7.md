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
