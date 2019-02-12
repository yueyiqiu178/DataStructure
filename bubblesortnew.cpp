#include <iostream>
using namespace std;

void bubblesort(int [],int);
     
     
int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
    cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   bubblesort(num,10);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void bubblesort(int a[],int n){
     int i,j,tmp,flag=1;
     for(i=n-1;flag&&i>=1;i--){
             flag=0;
             for(j=0;j<i;j++){
                 if(a[j]>a[j+1]){
                         tmp=a[j];
                         a[j]=a[j+1];
                         a[j+1]=tmp;
                         flag=1;  
             }
             
             }
     }
     
     
     }
