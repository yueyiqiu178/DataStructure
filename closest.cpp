#include <iostream>
#include <time.h>
#include<math.h>
using namespace std;

void closest(int []);
void rearrange(int [],int,int);
     
int main()
{   
    srand(time(NULL));
    
    int num[6]={5,19,9,3,10,14};
    
    for(int i=0;i<6;i++)
      num[i] = rand() % 100;
      
    for(int i=0;i<6;i++)
       cout<<num[i]<<" ";
       cout<<endl;
        
    closest(num); 
   
    int x[]={-37,-41,19,81,-45,25,56,61,-49,-10};
    rearrange(x,0,9);
    
     for(int i=0;i<10;i++)
       cout<<x[i]<<" ";
       cout<<endl;
    
      
	system("pause");
	return 0;
}


void closest(int a[]){
     
      int x,y,min=20000;
      for(int i=0;i<6;i++)
      for(int j=0;j<6;j++){
           if(i==j)
           continue;
           
           if(abs(a[j]-a[i])<min){
            x=i;
            y=j;
            min=abs(a[j]-a[i]);        
            }
              }
     
      cout<<a[x]<<" "<<a[y]<<endl;      
      
     }
     
     
void rearrange(int a[],int left,int right){
        int i=left;
        int j=right;
        int tmp;
       
        
        while(true){
                    
              while(a[i]<0&&i<=right)     
                   i++;
              while(a[j]>0)     
                   j--;
              if(i>=j)
              break;
                   
              tmp=a[i];
              a[i]=a[j];
              a[j]=tmp;
                   
                   
                   }
                              
        
              
     }
