function solution(s) {
    let answer = 1000;
    if(s.length == 1){
        return 1
    }
    for(let i = 1; i < parseInt(s.length / 2) +1 ; i++){
        let result = '';
        let before = '';
        let cnt = 1;
        for(let j = 0; j < s.length; j += i){
            if(before === s.slice(j,j+i)){
                cnt += 1;
            }else if(j != 0){
                if(cnt > 1){
                    result += cnt;
                }
                result += before;
                before = s.slice(j,j+i);
                cnt = 1;
            }
            else{
                before = s.slice(j,j+i);
            }
        }
        if(cnt > 1){
            result += cnt;
        }
        result += before;
        if (answer > result.length){
            answer = result.length;
        }
    }
    return answer;
}