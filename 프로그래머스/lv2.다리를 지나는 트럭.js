// Level: 다리를 지나는 트럭
function solution(bridge_length, weight, truck_weights) {
    let answer = 0;
    let queue = [];
    let cur_weight = 0;
    let cur_idx = 0;
    for(let i = 0; i < bridge_length; i++){
        queue.push(0);
    }
    while(cur_idx < truck_weights.length){
        answer += 1;
        cur_weight -= queue[0];
        queue.shift();
        if(cur_weight + truck_weights[cur_idx] <= weight){
            queue.push(truck_weights[cur_idx]);
            cur_weight += truck_weights[cur_idx];
            cur_idx += 1;
        }else {
            queue.push(0);
        }
    }
    answer += bridge_length;
    return answer;
}