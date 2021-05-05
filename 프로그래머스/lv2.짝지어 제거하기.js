//  Level2: 짝지어 제거하기
function solution(s)
{
    let stack = [];
    s.split("").forEach(ele => {
        if(stack.length > 0 && stack[stack.length-1] === ele) stack.pop();
        else stack.push(ele);
    });
    if(stack.length === 0) return 1
    return 0
}