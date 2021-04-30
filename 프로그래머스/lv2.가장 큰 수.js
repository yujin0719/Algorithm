// Level2: 가장 큰 수
function solution(numbers) {
    let number = []
    numbers.forEach(ele => number.push(String(ele)));
    const num = number.sort((a,b) => ((b+a)*1)-((a+b)*1)).join('');
    const result = numbers.sort((a,b) => ((b+''+a)*1-(a+''+b)*1)).join('');
    return result[0] === '0' ? '0': result;
}