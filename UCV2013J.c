#include <iostream>
#include<stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    while(n!=0){
        int a[n];
        for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        }
      int flag=1;
        int l=0,sum=0,ans=0,final=0;
        while(flag){
            sum+=pow(2,l);
            l++;
            if(sum>=n){
                final=sum;
                flag=0;
                l--;
                sum=sum-pow(2,l);
                for(int k=sum;k<n;k++){
                    ans+=a[k];
                }
                int flag2=1,z=1,x=1;
                while(flag2){
                if(n<final-x){
                    ans+=a[sum-z];
                    x=x+2;
                    z++;
                }
                else{
                    flag2=0;
                }
                }
            }
        }
        printf("%d\n",ans);
        scanf("%d",&n);
}
    return 0;
}

