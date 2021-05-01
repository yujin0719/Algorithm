// Level2: 위장
function solution(clothes) {
    let answer = 1;
    let closet = new Map()
    clothes.forEach((ele) => {
        if(closet.has(ele[1])) {
            let arr = closet.get(ele[1]);
            arr.push(ele[0]);
            closet.set(ele[1],arr);
        }
        else closet.set(ele[1],[ele[0]]);
    });
    closet.forEach((ele) => {
        answer *= (ele.length+1);
    });
    return answer-1;
}