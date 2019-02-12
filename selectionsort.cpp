#include <iostream>
using namespace std;

void selection_sort(int []);

int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   selection_sort(num);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
	getchar();
	return 0;
}


void selection_sort(int x[]) { 
     
     
     int i,j,min,tmp;
     
     
     for(i=0;i<9;i++){
     min=i;
     for(j=i+1;j<10;j++){
       if(x[j]<x[min])
          min=j;
          }
       tmp=x[i];
       x[i]=x[min];
       x[min]=tmp;
       }   
          
 } 
