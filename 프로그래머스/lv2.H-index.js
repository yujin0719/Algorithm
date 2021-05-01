// Level2: H-index
function solution(citations) {
    const m = Math.max(...citations);
    for(let i = m; i >= 0; i-= 1){
        let h_index = 0;
        citations.forEach((ele) => {
           if(ele >= i){
               h_index += 1;
           } 
        });
        if(h_index >= i) return i;
    }
    return 0;
}