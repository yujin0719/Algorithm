# 프로그래머스 문제풀이 - JavaScript Level2
### 1. 124 나라의 숫자
    function solution(n) {
        return n ? solution(parseInt((n - 1) / 3)) + [1,2,4][(n - 1) % 3] : '';
    }
    
### 2. 가장 큰 정사각형 찾기
