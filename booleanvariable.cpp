#include <iostream>
#include<iomanip>

using namespace std; 
void printout(bool []);


int main(void) { 
    
     bool a[5];
     int n=5;
     
     for(int i=0;i<n;i++)
       a[i]=false;
    
    
    while(!a[0]){
          
         printout(a);  
         
         int j=n-1;
         a[n-1]=!a[n-1];
         while(!a[j]){
                   
             j--;         
             a[j]=!a[j];         
                      
                      }   
            
            
            }
    
    
    
    
     system("pause");
     return 0; 
} 




void printout(bool x[]){
     
    /* for(int i=1;i<5;i++){
        if(x[i])
        cout<<setw(8)<<"True,";
        else
        cout<<setw(8)<<"False,";
        
        }
     cout<<endl;*/
     
     for(int i=1;i<5;i++)
       cout<<x[i]<<" ";
     cout<<endl;
     
     }

