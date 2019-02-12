#include <iostream>

using namespace std;

void bubble_sort(int []);

int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   bubble_sort(num);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
       cout<<num[i]<<"  ";
       
    cout<<endl;    
    
    
       
	getchar();
	return 0;
}


void bubble_sort(int x[]){
     int i,j,tmp;
     
     
     for(i=10;i!=1;i--)
     for(j=0;j<9;j++){
       if(x[j]>x[j+1]){
       tmp=x[j];
       x[j]=x[j+1];
       x[j+1]=tmp;
     }
}
       

}
