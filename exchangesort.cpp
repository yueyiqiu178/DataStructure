#include <iostream>
using namespace std;

void exchange_sort(int [],int);

int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   exchange_sort(num,10);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
	getchar();
	return 0;
}


void exchange_sort(int x[],int n) { 
     
     int i,j,temp;
     
     for(i=0;i<n-1;i++)
     for(j=i;j<n;j++)
         if(x[j]<x[i]){
           temp=x[i];              
           x[i]=x[j];             
           x[j]=temp;             
             }   
             
 } 
