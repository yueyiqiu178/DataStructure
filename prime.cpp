#include<iostream>

using namespace std;

void f(int &,int &);

int main(void)
{
     int a[101];
     for(int i=2;i<=100;i++)
        a[i]=1;
    
     for(int i=2;i<=100;i++){
          if(a[i]){
              cout<<i<<"  ";
            for(int k=i+i;k<=100;k+=i)
                    a[k]=0;
                      
       }
       }
       
       int x=10;
       f(x,x);
       
       cout<<x<<endl;
       
       
       
       double a1=999.999;
       float a2=999.999;
       cout<<a1<<" "<<a2<<endl;
       
       
       system("pause");
       return 0;
}


void f(int &y,int &b){
      y=y+10;
     
     b=b+20;
     
     }
