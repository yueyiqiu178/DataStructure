#include <iostream>
#include <time.h>
using namespace std;

void quicksort(int [],int,int);
int partition(int [],int,int);
     
int main()
{
   int i; 
   srand(time(NULL));
   int num[10]={37,41,19,81,45,25,56,61,49,10};
    cout<<"排序前:";
   for(i=0;i<10;i++){	 
     num[i] = rand() % 100;
     cout<<num[i]<<"  ";}
   quicksort(num,0,9);
   cout<<endl;
   cout<<"排序後:";
       for(i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}



void quicksort(int a[],int left,int right){
        int mid;
        if(left<right){
         mid=partition(a,left,right);
           
         quicksort(a,left,mid-1);
         quicksort(a,mid+1,right);
         
    }
     
     }
     
     
     
int partition(int a[],int left,int right){
        int i=left+1;
        int j=right;
        int tmp;
        int pivot=a[left];
        
        while(true){
                    
              while(a[i]<pivot&&i<right)     
                   i++;
              while(a[j]>pivot)     
                   j--;
              if(i>=j)
              break;
                   
              tmp=a[i];
              a[i]=a[j];
              a[j]=tmp;
                   
                   
                   }
                              
         tmp=a[left];
         a[left]=a[j];
         a[j]=tmp;
         
       
     
      return j;
      
}
