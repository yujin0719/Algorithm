// 로또의 최고 순위와 최저 순위
function solution(lottos, win_nums) {
    let zero = 0, cnt = 0;
    for (let num of win_nums){
        if(lottos.includes(num))
            cnt += 1;
    }
    const zeroArr = lottos.filter(x => x === 0)
    const row = 7 - cnt < 6 ? 7 - cnt : 6;
    const high = 7 - (cnt + zeroArr.length) < 6 ? 7 - (cnt + zeroArr.length) : 6;
    return [high,row]
}