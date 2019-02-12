#include<iostream>
#include<time.h>
using namespace std;

void MaxMin(int [],int &,int &,int);
void MaxMin_2(int [],int,int &,int &);

int main(void)
{
     srand(time(NULL));
    
    int max,min,n;
    int data[10];
    
    for(int i=0;i<10;i++)
      data[i]=rand()%100;
      
    cout<<"皚戈:";
      
    for(int i=0;i<10;i++)
      cout<<data[i]<<" "; 
      cout<<endl;
       
    MaxMin(data,max,min,9);
    
    cout<<"程计"<<max<<"程计"<<min<<endl; 
    
    
    
     for(int i=0;i<10;i++)
      data[i]=rand()%100;
      
    cout<<"皚戈:";
      
    for(int i=0;i<10;i++)
      cout<<data[i]<<" "; 
      cout<<endl;
       
    MaxMin_2(data,10,max,min);
    
    cout<<"程计"<<max<<"程计"<<min<<endl; 
    
    
    
     system("pause");
       return 0;
}


void MaxMin(int a[],int &max,int &min,int n){
     if(n==0)
        max=min=a[0];
     else{ 
        MaxMin(a,max,min,n-1);
        if(a[n]>max)
        max=a[n];
        if(a[n]<min)
        min=a[n];
     }
     }
     
void MaxMin_2(int a[],int n,int &max,int &min){
     int i;
     if(n%2==1){
           max=min=a[0];
           i=1;     
                }
     else{
          if(a[0]>a[1]){max=a[0];min=a[1];}
          else{min=a[0];max=a[1];}  
          i=2;
          }
     while(i<n){
            if(a[i]>a[i+1]){
                if(a[i]>max)
                max=a[i];
                if(a[i+1]<min)            
                min=a[i+1];            
                            }    
             else{
                 if(a[i+1]>max) 
                  max=a[i+1];
                  if(a[i]<min)
                  min=a[i];
                  
                  }   
                
                i=i+2;
                
                
                }
     
     
     
     }
