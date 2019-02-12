#include <iostream>
using namespace std;

void selectionsort(int [],int);
int findmin(int,int,int []);   
     
int main()
{
   int num[]={10,41,19,81,45,25,56,61,49,37};
    cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   selectionsort(num,10);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void selectionsort(int a[],int n){
     int k,tmp,i;
     for(i=0;i<n;i++){
     k=findmin(i,n,a);
     tmp=a[i];
     a[i]=a[k];
     a[k]=tmp;
     }
     
     
     
     }
     
     
     
int findmin(int k,int n,int a[]){
    int index=k;
  
    for(int i=k+1;i<n;i++){
        
    if(a[i]<a[index]){
    index=i;
      
               }
               
               
}
    return index;
}
