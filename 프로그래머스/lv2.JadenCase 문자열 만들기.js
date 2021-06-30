// Level2: JadenCase 문자열 만들기
function solution(s) {
    let answer = '';
    s = s.toLowerCase();
    s = s.split("");
    s.map((e,i) => {
        if(i === 0 || s[i-1] === ' '){
            answer += e.toUpperCase();
        }
        else answer += e;
    })
    return answer;
}