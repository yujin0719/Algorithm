// Level2: 최솟값 만들기
function solution(A,B){
    let answer = 0;
    A.sort((a,b) => a-b);
    B.sort((a,b) => b-a);
    A.map((e,i) => answer += (e*B[i]));
    return answer;
}