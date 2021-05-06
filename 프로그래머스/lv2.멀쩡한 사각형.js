// Level2: 멀쩡한 사각형
function solution(w, h) {
    const gcd = function(a,b){
        if(b === 0) return a;
        if(a % b === 0) return b;
        else return gcd(b,a%b);
    }
    const GCD = gcd(w,h);
    return w*h - (w+h-GCD);
}