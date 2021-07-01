// Level1: 체육복
function solution(n, lost, reserve) {
    let copy_lost = [...lost];
    lost = lost.filter(e => !reserve.includes(e));
    reserve = reserve.filter(e => !copy_lost.includes(e));
    let answer = n - lost.length
    lost.sort((a,b) => a-b);
    lost.map((e,i) => {
        if(reserve.includes(e-1)){
            const idx = reserve.indexOf(e-1);
            reserve.splice(idx,1);
            answer += 1;
        }
        else if(reserve.includes(e+1)) {
            const idx = reserve.indexOf(e+1);
            reserve.splice(idx,1);
            answer += 1;
        }
    })
    return answer;
}