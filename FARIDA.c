#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{

    int t;
    scanf("%d",&t);
    while(t--){
        string s3;
        cin>>s3;
        int len=s3.length();
        string s;
        cin>>s;
        int vv=0;
        bool cycle=true;
        int arr[len];
        for(int rr=0;rr<len;rr++){
        //   int x=pow(10,len-rr);
        /// arr[rr-1]=a/x;
        //  a=a-arr[rr-1]*x;
        arr[rr]=s3[rr]-'0';
        }
        string s2;
        int lenst=s.length();
        for(int t=0;t<lenst;t++){
        //    int x=pow(10,len-vv);
          ///  printf("%d\n",x);
             //printf("%d\n",arr[vv]);
             // printf("%d\n",a/x);
            int c=s[t]-'a'-arr[vv];
            int ff;
           // printf("%d\n",c);
           if(c>0){
            ff=c%26;
           }else{
            ff=(26-abs(c))%26;
           }
            //printf("%d\n",ff);
            char cc='a'+ff;
            //printf("%c\n",cc);
            s2+=cc;
            if(cycle){
            vv++;
            }
            else{
                vv--;
            }
            if(vv==len){
                vv--;
                cycle=false;
            }
            if(vv==-1){
                vv=0;
                cycle=true;
            }
        }
        cout<<s2;
        printf("\n");
    }
}
