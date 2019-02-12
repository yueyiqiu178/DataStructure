#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;
 
double sin(double,int);
double expo(double,int);
int fact(int);
 
 
 
int main(void)
{
      double x;
      cin>>x;
      cout<<sin(x,1)<<endl;
      
    
       system("pause");
       return 0;
}



double sin(double x,int i){
      double t=expo(x,i)/fact(i);
         if(t>0.000001)
         t=t-sin(x,i+2);
    
    return t;
}



double expo(double x,int i){
     
     if(i==1)
     return x;
     else{
     for(int j=2;j<=i;j++){
        x=x*x;}
     return x;   
        }
    
    
}

int fact(int t){
      int s=1; 
      for(int i=1;i<=t;i++)
        s*=i;
    
    return s;
}   
    
    
    
    

