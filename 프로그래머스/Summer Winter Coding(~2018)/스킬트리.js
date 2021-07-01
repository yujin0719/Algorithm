// 스킬트리
function solution(skill, skill_trees) {
    let answer = 0;
    for(let tree of skill_trees){
        let queue = skill.split("");
        let check = true;
        tree.split("").map((e) => {
            if(queue.includes(e)){
                if(queue[0] == e) queue.shift();
                else check = false;
            }
        })
        if(check) answer += 1;
    }
    return answer;
}