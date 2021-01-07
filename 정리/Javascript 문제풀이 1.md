# 프로그래머스 문제풀이 - JavaScript Level1
### 1. 2016
    function solution(a, b) {
        const month = [31,29,31,30,31,30,31,31,30,31,30,31];
        const week = ["THU","FRI","SAT","SUN","MON","TUE","WED"]
        var sum = 0;
        for (var i  = 0; i < a -1; i++){
            sum += month[i];
        }
        sum += b;
        return week[sum % 7]
    }

- 변수

    - var: 변수 재할당, 재선언 가능 matable

    - let: 변수 재할당 가능, 재선언 불가능 immutable

    - const(상수): 재선언, 재할당 모두 불가능 immutable

    - hoisting: var 선언문이나 fuction 선언문을 해당 scope 위로 끌어올리는 것 (var는 function-scoped, let, const는 block scoped)

        - **var는 할당한 뒤 선언가능**

        - **let은 선언하고 할당**

        - **const는 선언과 동시에 할당**
  
- Date 객체

    - 객체 생성 : 날짜를 나타내는 **문자열 반환**
      - 현재시간 반환

            new Date();
      - 구성 요소(연, 월, 일, 시, 분, 초, 밀리초)를 모두 매개변수의 값에서 가져오는 Date 객체를 생성

            new Date(year, monthIndex[, day[, hour[, minutes[, seconds[, milliseconds]]]]]);
      - 메소드

        - getDay(): 주어진 날짜의 요일 반환
  
  
### 2. 가운데 글자 가져오기
    function solution(s) {
        const l = Math.ceil(s.length/2);
        return s.length % 2 == 0 ? s[l-1] + s[l] : s[l-1];
    }
    

### 3. 같은 숫자는 싫어
    function solution(arr){
        return arr.filter((element,idx) => element != arr[idx+1]);
    }

- filter

  - callback 함수 조건에 만족하는 요소를 구성으로하는 배열을 생성하는 함수
  
  - element: 요소 값
  
  - index: 요소의 index
  
  - array: 사용되는 배열의 객체
  
        var newArray = arr.filter((element, index, array) => {});
