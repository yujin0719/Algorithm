# 프로그래머스 문제풀이 - JavaScript Level1

### 26. 하샤드 수
    function solution(x) {
        var total = String(x).split("").reduce((a,c) => Number(a) + Number(c));
        console.log(total);
        return x % total === 0 ;
    }
### 27. 핸드폰 번호 가리기
    function solution(phone_number) {
        return '*'.repeat(phone_number.length - 4) + phone_number.slice(-4);
    }
- slice 

  - Array.prototype.slice():배열의 begin부터 end까지(end 미포함)에 대한 복사본을 새로운 배열 객체로 반환하는 메소드
      
        arr.slice([begin[, end]])
        
  - String.prototype.slice(): 문자열의 일부를 추출하면서 새로운 문자열을 반환하는 메소드 
  
        str.slice(beginIndex[, endIndex])
        
 ### 28. 행렬의 덧셈
 
 ### 29. x만큼 간격이 있는 n개의 숫자
      function solution(x, n) {
          return Array(n).fill(x).map((v,i) => v = x * (i+1));
      }
### 30. 직사각형 별 찍기 
    
