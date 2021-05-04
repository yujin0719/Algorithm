// 오픈채팅방
function solution(record) {
    let answer = [];
    let chat = new Map();
    record.forEach((ele) => {
        ele = ele.split(' ');
        if(ele[0] != 'Leave') chat.set(ele[1],ele[2]);
    });
    record.forEach((ele) => {
        ele = ele.split(' ');
        if(ele[0] === 'Enter') answer.push(`${chat.get(ele[1])}님이 들어왔습니다.`);
        if(ele[0] === 'Leave') answer.push(`${chat.get(ele[1])}님이 나갔습니다.`);
    });
    return answer;
}