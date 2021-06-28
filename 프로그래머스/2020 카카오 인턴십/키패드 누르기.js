// 키패드 누르기
function solution(numbers, hand) {
    let answer = '';
    const div = [3,0,0,0,1,1,1,2,2,2,3,3,3]
    let left = 10, right = 12;
    numbers.map(num => {
        if(num == 0) num = 11;
        if(num % 3 === 1){
            answer += 'L';
            left = num;
        }
        else if(num % 3 === 0){
            answer += 'R'
            right = num;
        }
        else {
            const left_dist = left % 3 === 1 ? Math.abs(div[left]-div[num]) + 1 :  Math.abs(div[left]-div[num]);
            const right_dist =  right % 3 === 0 ? Math.abs(div[right]-div[num]) + 1 :  Math.abs(div[right]-div[num]);
            if(left_dist === right_dist){
                if(hand === 'right'){
                    answer += 'R';
                    right = num;
                }
                else {
                    answer += 'L';
                    left = num;
                }
            }
            else if(left_dist > right_dist){
                answer += 'R';
                right = num
            }
            else {
                answer += 'L';
                left = num
            }
        }
    });
    return answer;
}