#include <iostream>
using namespace std;

void merge(int[],int[],int[],int,int);

int main()
{
   int i; 
  
   int num1[10]={10,19,25,37,41,45,49,56,61,81};
   int num2[5]={15,32,37,38,50};
   int result[15];
    cout<<"合併前:"<<endl;
   for(i=0;i<10;i++)	 
    cout<<num1[i]<<" ";
    cout<<endl;
    for(i=0;i<5;i++)	 
    cout<<num2[i]<<" ";
    cout<<endl;
    
   merge(num2,num1,result,5,10);
   cout<<endl;
   cout<<"合併後:";
       for(i=0;i<15;i++)	 
          cout<<result[i]<<"  ";
          
    cout<<endl;      
   
      
	system("pause");
	return 0;
}


void merge(int x[],int y[],int z[],int q1,int q2){
     
      int i=0,j=0,k=0;
      
      while(i<q1&&j<q2){
                        
         if(x[i]<=y[j])
           z[k++]=x[i++];
         else
           z[k++]=y[j++];                                        
         }
     
       while(i<q1)
        z[k++]=x[i++];
       
       while(j<q2)
        z[k++]=y[j++]; 
     
     
     }
