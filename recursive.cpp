#include<iostream>
using namespace std;

int fact(int);
int fact_recursive(int);
int sum_recursive(int);
int findmax_recursive(int[],int);
int sumarray_recursive(int [],int);
int pi(int,int);
int crosssum(int,int);
int division(int,int);
int mod(int,int);
int mul(int,int);
int exp2(int,int);
int mul2(int x,int y);
int gcd_recursive(int,int);
int gcd(int,int);
int fib(int);
int fib_recursive(int);
int comb_recursive(int,int);
int comb(int,int);
int ack(int,int);
void hanoiTower_recursive(int,char,char,char);

int main(void){
    int k;
    //cin>>k;
    //int m[]={90,5,12,8,12};
    //cout<<sumarray_recursive(m,5)<<endl;
    //cout<<ack(2,2)<<endl;
    //hanoiTower_recursive(3,'A','B','C');
    
    //cout<<crosssum(1,3)<<endl;
    cout<<gcd_recursive(5,8)<<endl;
    
    system("pause");
    return 0;
    
    }


int fact(int n){
    int s=1;
    for(int i=1;i<=n;i++)
        s=s*i;
    
    return s;
    
}


int fact_recursive(int n){
     if(n<=1)   
       return 1;
     else
        return n*fact_recursive(n-1);
      
}


int sum_recursive(int n){
    if(n<=0)
    return 0;
    else
    return n+sum_recursive(n-1);    
}

int findmax(int a[],int n){
    if(n==1)
    return a[1];
    else{
         int m=findmax_recursive(a,n-1);
         return a[n]>m?a[n]:m;
}
}

int findmax_recursive(int a[], int n)
{
int t;
if( n > 1 )
{
t = findmax_recursive(a, n-1);

if( t > a[n-1] )
return t;
else
return a[n-1];
}


else if( n == 1 )
return a[n-1];
}


int sumarray_recursive(int a[],int n){
    if(n<0)
    return 0;
    else
    return sumarray_recursive(a,n-1)+a[n];
    
}

int pi(int m,int n){
    if(m==n)
    return n;
    else
    return m*pi(m+1,n);
       
}


int crosssum(int m,int n){
    if(m==n)
    return n;
    else
    return m-crosssum(m+1,n);   
}

int division(int x,int y){
    if(x>=y)
    return division(x-y,y)+1;
    else
    return 0;    
}


int mod(int x,int y){
     if(x>=y)
       return mod(x-y,y);
     else
       return x;    
}


int mul(int x,int y){
 if(y>0)
 return mul(x,y-1)+x;
 else
 return 0;   
}


int exp(int x,int y){
     if(y>0)   
        return exp(x,y-1)*x;
     else return 0;    
}


int mul2(int x,int y){
 
      if(y==0)
         return 0;
      else{
          int p=mul2(x,y/2);
          return p+p+(y%2)*x; 
}

}



int exp2(int x,int y){
    if(y==0)
       return 1;
    else{
       int p=exp2(x,y/2);  
       if(y%2==0)
         return p*p;
        else
          return p*p*x; 
         
         }
}


int gcd(int a,int b){
    
    int c;
    while(b){
       
          c=a%b;
          a=b;
          b=c;
          
    
     }
     return a;  
}


int gcd_recursive(int a,int b){
    
    if(b)
      return gcd_recursive(b,a%b); 
    else
      return a;
    
}


int fib(int n){
       
     int current=1;
     int next=1;
     int sum;
     
     if(n==1||n==2)
     return 1;
     else{
     for(int i=3;i<=n;i++){  
            sum=current+next;
            current=next;
            next=sum; }
            
            return next;
                       
}
}


int fib_recursive(int n){
    
    if(n==1||n==2)
      return 1;
    else
      return fib_recursive(n-1)+fib_recursive(n-2);
    
}



int comb_recursive(int m,int n){
    if(n==0||n==m)
      return 1;
    else
      return comb_recursive(m-1,n)+comb_recursive(m-1,n-1);   
}


int comb(int m,int n){
      
      int i,j;
      int a[m];
      for(i=0;i<m;i++)
           a[i]=1;
      
      for(i=1;i<=m-n;i++){
                          
              for(j=1;j<=n;j++)
              a[j]=a[j]+a[j-1];
              
              
              }          

    return a[n];
    
}



int ack(int m,int n){
    
    if(m==0)   
       return n+1;
    else if(n==0)   
       return ack(m-1,1);
    else
       return ack(m-1,ack(m,n-1));     
}


void hanoiTower_recursive(int n,char source,char temp,char dest){
      if(n){
           hanoiTower_recursive(n-1,source,dest,temp);
           cout<<"Move disk"<<n<<" from "<<source<<" to "<<dest<<endl;
           hanoiTower_recursive(n-1,temp,source,dest);
     
     }
     
     }

