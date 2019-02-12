#include <iostream>
#include <time.h>
using namespace std;

void distributionsort(int [],int[],int,int);

     
int main()
{
   int i; 
   srand(time(NULL));
   int num[15]={8,3,2,2,1,4,6,5,4,1,3,7,3,7,2};
   int result[15]={0};
    cout<<"排序前:";
   for(i=0;i<15;i++){	 
     num[i] = rand() % 10;
     cout<<num[i]<<"  ";}
    
   distributionsort(num,result,15,10);
   
   cout<<endl;
   cout<<"排序後:";
       for(i=0;i<15;i++)	 
          cout<<result[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void distributionsort(int a[],int b[],int n,int k){
     
     int count[k];
     
     
     for(int i=0;i<k;i++)
        count[i]=0;
    
        
     
        
     for(int i=0;i<n;i++) 
       count[a[i]]++;
     
     for(int i=1;i<k;i++)
        count[i]=count[i-1]+count[i];
     
        
     for(int i=0;i<n;i++){ 
        b[--count[a[i]]]=a[i];
        
        }
     
     
     }
     
     
