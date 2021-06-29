// 이진 변환 반복하기
function solution(s){
    let times = 0;
    let zero = 0;
    while(s != '1'){
        times += 1;
        zero += s.length;
        s = s.replace(/0/g,"");
        zero -= s.length
        s = s.length.toString(2);
    }
    return [times,zero]
}