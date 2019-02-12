#include<iostream>
#define MaxN 100

using namespace std;

int set(int);

int main(){
    
    cout<<set(3)<<endl;
    
    system("pause");
    return 0;
    
    }
    
    
int set(int n){
    int a[3][MaxN];
    a[0][1]=1;
    a[1][1]=1;
    a[2][1]=1;
    
    for(int i=2;i<=n;i++){
            a[0][i]=a[0][i-1]+a[1][i-1]+a[2][i-1];
            a[1][i]=a[0][i-1]+a[2][i-1];
            a[2][i]=a[0][i-1]+a[1][i-1];
            
            }
     
      int result=a[0][n]+a[1][n]+a[2][n]; 
       
       return result;;    
    
    }





