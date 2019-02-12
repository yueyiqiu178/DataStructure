#include <iostream>
#include <time.h>
using namespace std;

void countsort(int [],int[],int);

     
int main()
{
   int i; 
   srand(time(NULL));
   int num[10]={37,41,19,81,45,25,56,61,49,10};
   int result[10]={0};
    cout<<"排序前:";
   for(i=0;i<10;i++){	 
     num[i] = rand() % 100;
     cout<<num[i]<<"  ";}
    
   countsort(num,result,10);
   cout<<endl;
   cout<<"排序後:";
       for(i=0;i<10;i++)	 
          cout<<result[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void countsort(int a[],int b[],int n){
     
     int count[n];
     for(int i=0;i<n;i++)
        count[i]=0;
     
     
     for(int i=0;i<n;i++)
       for(int j=i+1;j<n;j++)
          if(a[j]<=a[i])
            count[i]++;
          else
            count[j]++;    
        
     for(int i=0;i<n;i++)
        b[count[i]]=a[i];
     
     
     }
     
     
