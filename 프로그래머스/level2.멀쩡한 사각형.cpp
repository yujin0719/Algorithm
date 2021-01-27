//level2. 멀쩡한 사각형

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    int gcd;
    int a = w;
    int b = h;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    gcd = a;
    long long inner = (w/gcd)+(h/gcd)-1;
    long long s = (long long)w * (long long)h;
    answer = s-(gcd*inner);
    return answer;
}
