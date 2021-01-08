# Java
### 21. 제일 작은 수 제거하기
    function solution(arr) {
      const m = Math.min(...arr);
      var answer = arr.filter((e) => e != m);
      return answer.length == 0 ? [-1] : answer;
  }
