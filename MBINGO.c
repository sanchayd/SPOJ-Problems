#include <iostream>
#include<stdio.h>
#include <cmath> 
using namespace std;

int main() {
    int n,b;
    scanf("%d %d",&n,&b);
    while(n!=0 && b!=0){
    bool arr[n+1];
    int a[b];
    for(int i=0;i<=n;i++){
    arr[i]=false;   
    }
    for(int k=0;k<b;k++){
         scanf("%d",&a[k]); 
    }
    for(int l=0;l<b;l++){
        for(int t=l;t<b;t++){
            int r=(a[l]-a[t]);
            if(r<0){
            r=-r;
            }
            if(arr[r]==false){
                arr[r]=true;
            }
        }
    }
    int flag=0;
    for(int ii=0;ii<=n;ii++){
        if(arr[ii]==false){
            printf("N\n");
            flag=1;
            break;
        }
    }if(flag==0){
        printf("Y\n");
    }
    scanf("%d %d",&n,&b);
    }
    return 0;
}

