#include<iostream>
#define N 10000
using namespace std;

void move(int,char,char,char);

int main(){
    
    
    move(3,'A','B','C');
    
    
    system("pause");
     return 0;
     
     
     }
     
     
     
     
void move(int n,char a,char b,char c){
     
       int s[N],sp=0;
       int t,i;
       
       L0:
           if(n){
                 s[sp++]=1;s[sp++]=n;s[sp++]=a;s[sp++]=b;s[sp++]=c;
                 n--;t=b;b=c;c=t;
                 goto L0;
       L1:
           cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
           s[sp++]=2;s[sp++]=n;s[sp++]=a;s[sp++]=b;s[sp++]=c;
           n--;
           t=a;a=b;b=t;
           goto L0;
       L2:;
           
       }    
                 
                 
                 
                 
     
     
     if(sp>0){
          c=s[--sp];b=s[--sp];a=s[--sp];n=s[--sp];i=s[--sp];
          switch(i){
                   case 1:goto L1;break;
                   case 2:goto L2;break; 
                    }    
              
              
              
              
              }
     
     
     
     }
