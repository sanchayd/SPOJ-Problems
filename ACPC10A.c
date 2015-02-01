#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>


using namespace std;


int main(){
 
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    while(a!=0 || b!=0  || c!=0){
    int aa=b-a;
    int bb=c-b;
        int cc=0;
        int dd=0;
        if(a!=0){
    cc=b/a;
        }
        if(b!=0){
     dd=c/b;
        }
    
    if(aa==bb){
        printf("AP %d\n",c+aa);
    }
    else if(cc==dd){
        printf("GP %d\n",c*cc);
    }
scanf("%d %d %d",&a,&b,&c);
    }
}
