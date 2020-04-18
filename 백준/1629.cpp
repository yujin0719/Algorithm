/*주의해야할 코드

ll POW3(11 a, ll b, ll m){
    if(b == 0) return 1;
    ll val = POW(a,b/2,m);
    val = val*val%m;
    if(b%2 == 0)
        return POW3(a,b/2,m)*POW3(a,b/2,m)%m;
    return POW3(a,b/2,m)*POW3(a,b/2,m)*a%m;
}
 중간 결과를 m으로 나누어주면서 계산을 한 것 같지만 b가 홀수일 때 POW3(a,b/2,m)*POW3(a,b/2,m)*a를 계산하면서 int overflow가 발생할 수 있다. POW3(a,b/2,m) , a 모두 최대 2^{32}-1이기 때문이다.
 또한  함수를 2번 호출함으로 인해 시간복잡도가 O(lg b)가 아닌 O(b)가 됩니다. 피보나치 함수를 재귀로 푸는 것과 유사한 상황인거죠. 이미 계산한 것을 중복으로 계산하지 않도록 조심해야합니다.
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
 ll POW(ll a, ll b, ll m){
   if(b==0) return 1;
   ll val = POW(a,b/2,m);
   val = val*val%m;

   if(b%2 == 0) return val;
   return val*a%m;
 }

 int main(void){
   ll a,b,c;
   cin >> a >> b >> c;
   cout << POW(a,b,c);
 }
