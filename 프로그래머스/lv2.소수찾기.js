const getPermutations = function(arr, selectNumber){
    const result = [];
    if(selectNumber === 1) return arr.map(ele => [ele]);
    arr.forEach((fixed,idx,origin) => {
		const rest = [...origin.slice(0,idx),...origin.slice(idx+1)];
		const permutaions = getPermutations(rest,selectNumber-1);
		const attached = permutaions.map((element) => [fixed,...element]);
		result.push(...attached);
		}
    );
    return result;
}
const isPrime = function(number){
    if(number <= 1) return false;
    for(let i = 2; i <= parseInt(Math.sqrt(number)); i++){
        if(number % i === 0) return false;
    }
    return true;
}
function solution(numbers) {
    let answer = 0;
    let candidates = new Set();
    const number = numbers.split("");
    for(let i = 1; i <= numbers.length; i++){
        const tmp = getPermutations(number,i);
        tmp.forEach((ele) => candidates.add(parseInt(ele.join(""))));
    }
    candidates.forEach((ele) => {
        if(isPrime(ele)) answer += 1;
           });
    return answer;
}