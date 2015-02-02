#include <iostream>
#include<stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
using namespace std;
//int movex[]={1,-1,0,0};
//int movey[]={0,0,1,-1};

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c;
        scanf("%d %d",&r,&c);
        int a[r][c];
        for(int k=0;k<r;k++){
            for(int j=0;j<c;j++){
                scanf("%d",&a[k][j]);
            }
        }
               int dp[r][c];
        dp[r-1][c-1]=0;
        dp[r-2][c-1]=-a[r-2][c-1];
        dp[r-1][c-2]=-a[r-1][c-2];
        for(int lr=r-2;lr>-1;lr--){
            dp[lr][c-1]=-a[lr][c-1]+dp[lr+1][c-1];
            if(dp[lr][c-1]<=0){
                dp[lr][c-1]=0;
            }
        }
        for(int lc=c-2;lc>-1;lc--){
            dp[r-1][lc]=-a[r-1][lc]+dp[r-1][lc+1];
            if(dp[r-1][lc]<=0){
                dp[r-1][lc]=0;
            }
        }
        for(int x=r-2;x>-1;x--){
            for(int y=c-2;y>-1;y--){
                dp[x][y]=-a[x][y]+min(dp[x+1][y],dp[x][y+1]);
               // printf("%d\n",dp[x][y]);
                if(dp[x][y]<=0){
                    dp[x][y]=0;
                }
            }
            
        }
        if(dp[0][0]==0){
            printf("1\n");
        }else{
        printf("%d\n",dp[0][0]+1);
        }
        }
    return 0;
}

