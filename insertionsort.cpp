#include <iostream>
using namespace std;

void insertion_sort(int []);

int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   insertion_sort(num);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
	system("pause");
	return 0;
}


void insertion_sort(int x[]){
     int i,j,k;
    
     
     for(i=1;i<10;i++){
        k=x[i];             
        j=i-1;
        while(j>=0&&k<x[j]){
            x[j+1]=x[j]; 
             j--;  }    
                              
          x[j+1]=k;                        
        
     
     }
}
