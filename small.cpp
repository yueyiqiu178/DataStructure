#include<iostream>

using namespace std;



int main(void)
{
    int x=3,y=5,p=1;
    while(y>0){
         if(y%2==1)      
               p=p*x;
               x=x*x;
               y=y/2;
               
               }
    cout<<p<<endl;
    
    
    int count=0;
    for(int i=1;i<=5;i++)
    for(int j=1;j<=i;j++)
    for(int k=1;k<=j;k++)
    count++;
    
    cout<<count<<endl;
    
    
    
    int a[3][5]={{50,20,14,17,9},
                 {21,2,47,11,74},
                 {54,38,14,74,56},
                 };
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*a<<endl;
    cout<<**(a+1)<<endl;
    cout<<*(*a+1)<<endl;;
    cout<<a[0]<<" "<<*a[1]<<" "<<a[2]<<" "<<**a<<endl;
    cout<<*(*a+0)<<" "<<*(*(a+0)+1)<<endl;
    cout<<*(*(a+1)+1)<<endl;
    
    
    
    
    system("pause");
       return 0;
}
    
