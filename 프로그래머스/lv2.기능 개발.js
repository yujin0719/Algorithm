function solution(progresses, speeds) {
    let answer = [];
    let work = progresses.map((progress,idx) => Math.floor((99-progress)/speeds[idx])+1);
    let days = 1, before = -1;
    for(let w of work){
        if(before >= w){
            days += 1;
        }else {
            answer.push(days);
            days = 1;
            before = w;
        }
    }
    answer.push(days);
    answer.shift();
    return answer;
}