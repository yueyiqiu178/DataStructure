#include<iostream>


using namespace std;

void Union(int [],int,int);
int find(int [],int);


int main(){
    
    int parent[]={0,4,-2,7,-3,7,7,-5,4,3,2};
    for(int i=1;i<=10;i++)
      cout<<parent[i]<<" ";
      cout<<endl;
      
    Union(parent,2,4);  
    
     for(int i=1;i<=10;i++)
      cout<<parent[i]<<" ";
      cout<<endl;
    
    cout<<find(parent,7)<<endl;
    cout<<find(parent,9)<<endl;
    
    for(int i=1;i<=10;i++)
      cout<<parent[i]<<" ";
      cout<<endl;
    
    system("pause");
    return 0;
    
    }
    
    
void Union(int a[],int x,int y){
     
     if(a[x]<=a[y]){
          
          a[x]=a[x]+a[y];
          a[y]=x;          
                    
                    }
     else{
          
          a[y]=a[y]+a[x];
          a[x]=y;
          
          }
     
     }
    
    
int find(int a[],int x){
     
       int i=x;
       while(a[i]>0)
         i=a[i];
       
        int j=x;
        int k;
        
        while(a[j]>0){
                      
         k=a[j];
         a[j]=i;
         j=k;              
                      }       
       
       return i;
          
    }
    

void check(int x[],int n){
     int count=0;
     bool checked[n];
     
     for(int i=0;i<n;i++)
       check[i]=false;
       
     for(int i=0;i<n;i++){
         if(x[i]==i)
          count++;
          
          
             
             
             
             
             }  
       
     
     
     }
