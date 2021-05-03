// 괄호변환
const divide = function(p){
    let open = 0, close = 0;
    for(let i = 0; i < p.length; i++){
        if(p[i] === '(') open += 1;
        else close += 1;
        if(open === close) return i
    }
}
const check = function(p){
    let open = 0;
    p = p.split("");
    p.forEach((ele) => {
        if(ele === '(') open += 1;
        else{
            if(open === 0) return false;
            else open -= 1;
        }
    });
    return open === 0; 
}
function solution(p) {
    let answer = '';
    if (p.length === 0) return p;
    const idx = divide(p);
    const u = p.slice(0,idx+1);
    const v = p.slice(idx+1);
    if(check(u)) {
        answer += u;
        answer += solution(v);
    }
    else {
        answer += '(';
        answer += solution(v);
        answer += ')';
        if(u.length > 2){
            const new_u = u.slice(1,u.length-1).split("");
            new_u.forEach((ele) => {
                if(ele === '(') answer += ')';
                else answer += '(';
            });
        }
    }
    return answer;
}