#include<iostream>

using namespace std;


struct RatNum{
       
       int p;
       int q;
       
       
       };

int gcd(int,int);
RatNum RatAdd(RatNum,RatNum);
RatNum RatSub(RatNum,RatNum);
RatNum RatMul(RatNum,RatNum);
RatNum RatDiv(RatNum,RatNum);

int main(void)
{
    
    RatNum a,b,c;
    a.p=2;
    a.q=30;
    
    b.p=20;
    b.q=200;
    
    c=RatSub(a,b);  
    cout<<c.p<<" "<<c.q<<endl;
    
    
    system("pause");
       return 0;
}



int gcd(int x,int y){
    
    
     int z;
     if(x<0)
     x=-x;
     if(y<0)
     y=-y;
     z=x%y;
     
     while(z){
              
          x=y;        
          y=z;
          z=x%y;        
                  }
                  
     return y;
    
    }
    
    
RatNum RatAdd(RatNum a,RatNum b){
       RatNum c;
       int g;
       
       c.p=a.p*b.p;
       
       c.q=a.q*b.p+a.p*b.q;
       
       g=gcd(c.p,c.q);
       c.p/=g;
       c.p/=g;
       
       return c; 
       }
       
RatNum RatSub(RatNum a,RatNum b){
       
       RatNum c;
       int g;
       
       c.p=a.p*b.p;
       
       c.q=a.q*b.p-a.p*b.q;
       
       g=gcd(c.p,c.q);
       c.p/=g;
       c.p/=g;
       
       return c;  
       
       }
       
       
RatNum RatMul(RatNum a,RatNum b){
       
       RatNum c;
       int g;
       
       c.p=a.p*b.p;
       
       c.q=a.q*b.q;
       
       g=gcd(c.p,c.q);
       c.p/=g;
       c.p/=g;
       
       return c;  
       
       }
       
RatNum RatDiv(RatNum a,RatNum b){
       
       RatNum c;
       int g;
       
       c.p=a.p*b.q;
       
       c.q=a.q*b.p;
       
       g=gcd(c.p,c.q);
       c.p/=g;
       c.p/=g;
       
       return c;  
       
       }
       

