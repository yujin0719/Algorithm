// 내적
function solution(a, b) {
    let answer = 0;
    a.map((e,i) => answer += (e * b[i]));
    return answer;
}