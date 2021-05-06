// 괄호 회전하기
function solution(s) {
    let answer = 0;
    const open = ['(','[','{'];
    const close = [')',']','}'];
    const check = function(par){
        let stack = [];
        par = par.split("");
        for(let i = 0; i < s.length; i++){
            if(open.includes(par[i]))
               stack.push(par[i]);
            else{
                if(stack.length > 0 && close.indexOf(par[i]) === open.indexOf(stack[stack.length-1]))
                    stack.pop();
                else return false;
            }
        }
        if(stack.length > 0) return false;
        return true;
    }
    for(let i = 0; i < s.length; i++){
        const st = s.slice(i) + s.slice(0,i);
        if(check(st)) answer += 1;
    }
    return answer;
}