#include<iostream>
using namespace std;

int count_of_set(int,int);

int main(void)
{
    
     
    cout<<"長度為2的序列集合個數為:"<<count_of_set(3,2)<<endl;
    
    
    system("pause");
       return 0;
}



int count_of_set(int k,int n){
      int a[k][n+1];
       a[0][1]=1;a[1][1]=1;a[2][1]=1;
       
      for(int i=2;i<=n;i++){
          a[0][i]=a[0][i-1]+a[1][i-1]+a[2][i-1];
          a[1][i]=a[0][i-1]+a[2][i-1];
          a[2][i]=a[0][i-1]+a[1][i-1];
        }
        
        return a[0][n]+a[1][n]+a[2][n];
}
