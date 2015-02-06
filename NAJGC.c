#include <iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;

ll getGCD(ll a, ll b) ;
int main() {
    ll t,a1,a2,b1,b2;
    scanf("%lld",&t);
    for(ll k=1;k<=t;k++){
        scanf("%lld %lld %lld %lld",&a1,&a2,&b1,&b2);
      ll num1=a1*(b1+1);
        ll num2=a2*(b2+1);
        ll denom=(a1+a2)*(b1+b2+1);
        ll num=num1+num2;
        if(a1+a2==0){
            printf("Case %lld: 0\n",k);
        }else{
ll dd=getGCD(num,denom);
ll numm=num/dd;
ll denomm=denom/dd;
printf("Case %lld: %lld/%lld\n",k,numm,denomm);
        
        }   
    }
    return 0;
}

ll getGCD(ll a, ll b) {
if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

