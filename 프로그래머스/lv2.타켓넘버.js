// Level2: 타켓넘버
function solution(numbers, target) {
    let answer = 0;
    function dfs(idx,total,numbers,target){
        if(idx === numbers.length){
            if(target === total) answer += 1;
        }
        else{
            dfs(idx+1,total+numbers[idx],numbers,target);
            dfs(idx+1,total-numbers[idx],numbers,target);
        }
    }
    dfs(0,0,numbers,target)
    return answer;
}