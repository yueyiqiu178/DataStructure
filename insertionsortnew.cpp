#include <iostream>
using namespace std;

void insertionsort(int [],int);
void insert(int,int,int []);
     
     
int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
    cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   insertionsort(num,10);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void insertionsort(int a[],int n){
     for(int i=1;i<n;i++)
         insert(i-1,a[i],a);
     
     }


void insert(int m,int x,int a[]){
     while(m>=0&&a[m]>x){
     a[m+1]=a[m];
     m--;}
     a[m+1]=x;
     
     }

