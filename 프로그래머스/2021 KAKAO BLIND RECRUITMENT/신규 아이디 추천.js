// 신규 아이디 추천
function solution(new_id) {
    let answer = '';
    // 1단계
    answer = new_id.toLowerCase();
    // 2단계
    let special = /[a-zA-Z0-9-_.]/;
    answer = answer.split("").filter(e => special.test(e)).join("");
    // 3단계
    answer = answer.replace(/\.+/g, '.')
    // 4단계
    answer = answer.replace(/^\.|\.$/g, '') 
    // 5단계
    answer = answer.replace(/^$/, 'a')
    // 6단계
    answer = answer.slice(0, 15).replace(/\.$/, '');
    // 7단계
    const l = answer.length
    answer = l > 2 ? answer : answer + answer.charAt(l - 1).repeat(3 - l);
    return answer;
}