#include <iostream>
using namespace std;


void shellsort(int [],int);

int main()
{
    
    
    int num[]={45,41,19,81,37,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
  shellsort(num,10);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
       cout<<num[i]<<"  ";
       
    cout<<endl;    
    
    
    
    
    	system("pause");
	return 0;
}


void shellsort(int a[],int n){
     
     int i,j,h,up;
     
     for(h=1;h<=n/9;h=3*h+1);
     
     for(;h>0;h=h/3)
     for(i=h;i<n;i++){
           up=a[i];
           j=i;
           while(j>=h&&a[j-h]>up){
                   a[j]=a[j-h];
                   j=j-h;                        
                                  }
           
           a[j]=up;
           }
     
     
     
     
     }
