// [3차]n진수 게임
function convert(total, base){
    const change = '0123456789ABCDEF';
    let result = '0';
    let num = 0;
    while(result.length <= total){
        let cur = num;
        let tmp = '';
        while (cur > 0){
            tmp += change[cur % base];
            cur = parseInt(cur/base);
        }
        result += tmp.split("").reverse().join("");
        num += 1;
    }
    return result
}
function solution(n, t, m, p) {
    const result = convert(t*m,n).split("");
    console.log(result)
    if(p == m) p = 0
    const answer = result.filter((e,i) => (i+1) % m == p && i / m < t).join("");
    return answer;
}