#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

#define MAXV 10000000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

stack<int> vertices;

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
//string toString(long long x)
//{
//    string ans;
//    do
//    {
//        ans+='0'+x%10;
//        x/=10;
//    }
//    while(x);
//
//    reverse(ans.begin(),ans.end());
//    return ans;
//}
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

vi G[MAXV], Grev[MAXV],finall[MAXV];
bool explored[MAXV];
int  location[MAXV], t = -1, V, E,countCC=0;
int parent[MAXV];
void dfs_reverse(int i) {
    explored[i] = true;
    location[i]=countCC;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it]){
            dfs_reverse(*it);
        }
}
void dfs(int i) {
    explored[i] = true;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
        if(!explored[*it]){
            dfs(*it);
        }
    vertices.push(i);
}
int main()  {
    int i, u, v, Q;
    scanf("%d %d", &V, &E); 
    for(i=0; i<E; i++)  {   
        scanf("%d %d", &u, &v);
        G[u].push_back(v);  
        Grev[v].push_back(u);   
    }
    memset(explored, false, V*sizeof(bool));
    for(i=0; i<V; i++)  {
        if(!explored[i]){
            dfs(i);
        }
    }
    memset(explored, false, V*sizeof(bool));
    countCC = 0;
    while(!vertices.empty()){
        int i=vertices.top();
        vertices.pop();
        if(!explored[i]) {
            dfs_reverse(i);
            countCC++;
        }
    }
   // printf("%d\n",location[4]);
    memset(parent,-1,sizeof(parent));
    for(int r=0;r<V;r++){
        if(parent[location[r]]==-1){
        parent[location[r]]=r;
        }
    }
    for(int t=0;t<V;t++){
        printf("%d\n",parent[location[t]]);
    }
    return 0;
}

