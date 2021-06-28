// 폰켓몬

function solution(nums) {
    const numbers = nums.filter((ele, idx) => nums.indexOf(ele) == idx);
    return Math.min(parseInt(nums.length/2), parseInt(numbers.length));
}