#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long toLong(string &s)
{
    long long ans=0;
    for(int i=0;i<s.size();++i)
        ans=ans*10+s[i]-'0';
    return ans;
}

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
int main()
{
    string s;
//    scanf("%lld",&a);
    while(cin>>s){
        long long a=0,b=0;
        string s2,s3,s4;
    char k,c;
    scanf("%c",&k);
     scanf("%c",&c);
    scanf("%c",&k);
    cin>>s2;
        string ss=s+k+c+k+s2+" = ";
        cout<<ss;
    int len=s.length();
    int len2=s2.length();
   // printf("%d\n",len);
    for(int i=0;i<len;i=i+2){
        int dd=s[i]-'0';
       // printf("%d\n",dd);
        //printf("%c\n",s[i+1]);
        for(int f=0;f<dd;f++){
        s3+=s[i+1];
        }
    }
    //cout<<s3;
   // printf("\n");
    int ll=s3.length();
   // a=stoll(s3);
        a=toLong(s3);
   for(int i=0;i<len2;i=i+2){
        
        int dd=s2[i]-'0';
        
        for(int f=0;f<dd;f++){
            s4+=s2[i+1];
        }
    }
  // b=stoll(s4);
        b=toLong(s4);
   // printf("%lld\n",b);
        long long jj;
        string s5,s6;
    if(c=='+'){
   //    printf("%lld\n",a+b);
        
      jj=a+b;
    }
    else if(c=='-'){
        // printf("%lld\n",a-b);
      
        jj=a-b;
    }
    else if(c=='*'){
        // printf("%lld\n",a*b);
       
        jj=a*b;
    }
    else if(c=='/'){
        //  printf("%lld\n",a/b);
       
        jj=a/b;
    }
        
        s5=toString(jj);
        long long count=1;
        int l=s5.length();
        s5[l]='-';
        for(int g=0;g<l;g++){
            
            if(s5[g+1]==s5[g]){
                count++;
            }
            
            else{
               // string s7=to_string(count);
                string s7=toString(count);
                s6+=s7;
                ///for(int y=0;y<count;y++){
                    s6+=s5[g];
                //}
                count=1;
            }
            
            if(count==9){
                string s7=toString(count);
                s6+=s7;
                ///for(int y=0;y<count;y++){
                s6+=s5[g];
                //}
                count=1;
                g++;
            }
        }
        cout<<s6;
        printf("\n");
    }
   }
