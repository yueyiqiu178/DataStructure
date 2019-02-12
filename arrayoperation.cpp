#include <iostream>
#include<iomanip>

using namespace std;

void array_insertion(int [],int &,int,int);
void array_deletion(int [],int &,int,int &);

int main(void) { 
    
    int temp;
    int a[10]={12,54,7,93,36,29};
    int n=6;
    array_insertion(a,n,3,90);
    array_deletion(a,n,1,temp);
    
    
    cout<<n<<endl;
    for(int i=0;i<10;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    
   
    
    
    
     system("pause");
     return 0; 
} 




void array_insertion(int x[],int &n,int i,int key){
     
     i--;
     
     for(int k=n;k>i;k--)
        x[k]=x[k-1];
     
     x[i]=key;
     n++;
     
     
     }
     
     
     
void array_deletion(int x[],int &n,int i,int &key){
     
     int k;
     
     key=x[--i];
     n--;
     
     for(k=i;k<=n;k++)
        x[k]=x[k+1];
     
    
     
     
     }


