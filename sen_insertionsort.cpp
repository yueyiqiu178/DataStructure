#include <iostream>
#define sentinel -20000
using namespace std;

void sentinelinsertion_sort(int []);

int main()
{
   int num[]={sentinel,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=1;i<10;i++)	 
     cout<<num[i]<<"  ";
    sentinelinsertion_sort(num);
   cout<<endl;
   cout<<"排序後:";
       for(int i=1;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
	system("pause");
	return 0;
}


void sentinelinsertion_sort(int x[]){
     
     int i,j,k;
    
     for(i=2;i<10;i++){
        k=x[i];             
        j=i-1;
        while(k<x[j]){
            x[j+1]=x[j]; 
             j--;  }    
                              
          x[j+1]=k;                        
        
     
     }



}
