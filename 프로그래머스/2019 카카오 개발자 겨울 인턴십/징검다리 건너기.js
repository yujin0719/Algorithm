// 징검다리 건너기
function solution(stones, k) {
    let answer = 0;
    let left = 1, right = Math.max(...stones);
    while(left <= right){
        const mid = Math.floor((left + right) / 2);
        let cnt = 0;
        for(let stone of stones){
            if(stone - mid <= 0) cnt += 1;
            else cnt = 0;
            if(cnt >= k) break;
        }
        if(cnt < k)left = mid + 1;
        else{
            answer = mid;
            right = mid - 1;
        }
    }
    return answer;
}