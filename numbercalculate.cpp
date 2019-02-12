#include<iostream>

using namespace std;

int P(int,int);


int main(){
    
      
    
     cout<<P(20,2)<<endl;
    
     system("pause");   
     return 0;
    
    
}



int P(int m,int n){
    
    if(n==0)
       return m;
    else
       return (P(m,n-1)*(m-2*n))/((2*n+1)*(2*n));
    
    
    }
