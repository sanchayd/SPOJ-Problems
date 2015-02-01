#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


//int mod = 1000000007;
//
//long long pwr(long long a,long long b,long long mod)
//{
//    if(b==0)
//        return 1;
//    long long temp=pwr(a,b/2,mod);
//    temp=(temp*temp)%mod;
//    if(b&1)
//        temp=(temp*a)%mod;
//    return temp;
//}
//long long pwr(long long a,long long b)
//{
//    if(b==0)
//        return 1;
//    long long temp=pwr(a,b/2);
//    temp=(temp*temp);
//    if(b&1)
//        temp=(temp*a);
//    return temp;
//}
//bool* isPrime;
//
//
//void generatePrimeSieve(const int lim)
//{
//    isPrime=(bool *)malloc(lim+1);
//    memset(isPrime,true,lim+1);
//    isPrime[0]=false;
//    isPrime[1]=false;
//    for(int i=2;i<=lim;++i)
//        if(isPrime[i]){
//            for(int j=i+i;j<=lim;j+=i){
//                isPrime[j]=false;
//               
//            }
//        }
//}
//
//
//long long toLong(string &s)
//{
//    long long ans=0;
//    for(int i=0;i<s.size();++i)
//        ans=ans*10+s[i]-'0';
//    return ans;
//}
string toString(long long x)
{
    string ans;
    do
    {
        ans+='0'+x%10;
        x/=10;
    }
    while(x);
    
    reverse(ans.begin(),ans.end());
    return ans;
}
//long long gcd(long long a,long long b)
//{
//    return b==0?a:gcd(b,a%b);
//}
//long long lcm(long long a,long long b)
//{
//    return (a/gcd(a,b))*b;
//}
//
//int isValid(int x,int y,int n,int m)
//{
//    if(x>=1 &&x<=n && y>=1 &&y<=m)
//        return 1;
//    return 0;
//}

int main()
{
    ll count[31];
    count[1]=1;
    
    for(int i=2;i<30;i++){
        count[i]=2*count[i-1];
    }
    
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        string s=toString(n);
        ll ans=1;
        int counter=1;
        int l=s.length();
        s[l]='-';
        for(int d=0;d<l;d++){
            if(s[d+1]==s[d]){
                counter++;
            }else{
                ans*=count[counter];
                counter=1;
            }
        }
        
        printf("%lld\n",ans);
    }
    
    
}

