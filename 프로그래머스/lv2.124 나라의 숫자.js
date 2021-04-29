// Level2: 124 나라의 숫자
function solution(n) {
    let answer = '';
    while(n > 0){
        n -= 1;
        answer = '124'[n%3] + answer
        n = parseInt(n / 3);
    }
    return answer;
}