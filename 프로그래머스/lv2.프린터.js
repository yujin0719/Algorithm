// Level2: 프린터
function solution(priorities, location) {
    let answer = 0;
    let queue = priorities.map((p,idx) => [p,idx]);
    while(true){
        let element = queue.shift();
        if(queue.some(m => m[0] > element[0])){
            queue.push(element);
        }
        else{
            answer += 1;
            if (element[1] === location){
                return answer;
            }
        }
    }
}