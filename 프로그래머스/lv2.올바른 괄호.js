// Level2: 올바른 괄호
function solution(s){
    let open = 0;
    s = s.split("");
    s.forEach((ele) => {
        if(open < 0) return false;
        else {
            if(ele === '(') open += 1;
            else open -= 1;
        }
    });
    return open === 0;
}