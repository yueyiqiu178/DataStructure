#include<iostream>

using namespace std;



int main(){
    
    int n=8;
    int i=1;
    int j;
    int row[9]={0};
    int count=1;
    
    
    while(i>0){
         row[i]++;
         if(row[i]>n) 
           i--;
         else{
              
             for(j=1;j<i&&row[j]!=row[i]&&abs(i-j)!=abs(row[i]-row[j]);j++);
             if(i==j){
                 
                 if(i<n){
                       i++;  
                       row[i]=0;  
                         }     
                 else{
                       
                      for(j=1;j<=8;j++)
                        cout<<"Queen"<<j<<"is on ("<<j<<","<<row[j]<<")"<<endl;
                        cout<<endl;
                        count++;
                       if(count==10) 
                         goto L1;
                      }     
                    
                      } 
              
               
              }     
               
               
               
               }
    L1:
    
    
    system("pause");   
    return 0;
    
    
}
