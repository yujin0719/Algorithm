// Level1: 모의고사
function solution(answers) {
    const student = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    let answer = [];
    let result = [];
    for(let i = 0; i < 3; i++){
        let cnt = 0
        const len = student[i].length
        for(let j = 0; j < answers.length; j++){
            if(answers[j] === student[i][j%len]) cnt += 1;
        }
        result.push(cnt);
    }
    const max_num = Math.max(...result);
    result.map((e,i) => {
        if(e === max_num){
            answer.push(i+1);
        }
    });
    return answer;
}