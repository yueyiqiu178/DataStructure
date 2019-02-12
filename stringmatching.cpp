#include<iostream>

using namespace std;


int main(void){
    
    
    char source[]={'S','a','b','c','b','a','a','b','c','a','b','c','a','c','a','b','b','a','c','a','a'};//20
    char pattern[]={'S','a','b','c','a','b','c','a','c','a','b'};//10
    int m=20,n=10;
    bool outerflag=false;
   
    
    for(int i=1;i<=m-n+1;i++){
            int p=i,q=1;
            bool flag=false;
            
            while(q<=n&&flag==false){
                                               
                if(pattern[q]==source[p])                               
                {
                  if(q!=n){
                   p++;
                   q++;}
                 else 
                   flag=true;
                 
                 }
                else
                break;
                
                }
              
              if(q==n&&flag==true){
               cout<<"Success"<<endl;
               outerflag=true;
               cout<<"在位置["<<i<<"]!"<<endl; 
               break;}
            
             
            }
        
        
           if(outerflag==false)
           cout<<"Failed"<<endl;
           
            cout<<"====================================="<<endl;
          cout<<"              KMP"<<endl;
           
           int i,j;
           int failure[11];
           failure[1]=0;
           for(j=2;j<=n;j++){
              i=failure[j-1];               
               while(pattern[j]!=pattern[i+1]&&i>0)              
                             i=failure[i];
               if(pattern[j]==pattern[i+1])              
                    failure[j]=i+1;
               else
                  failure[j]=0;            
                             }
           cout<<"Failure: ";
           for(int i=1;i<=10;i++)
              cout<<failure[i]<<" ";
          cout<<endl;
          
          
          int q=0;
          
          for(int i=1;i<=m;i++){
                  
            while(q>0&&pattern[q+1]!=source[i])
              q=failure[q];
              
              if(pattern[q+1]==source[i])
                 q++;
              if(q==n){ 
              cout<<"找到了"<<endl;
              break;} 
            }
        
        
           if(q!=n)
             cout<<"沒找到"<<endl;
          
          
    
    system("pause");
     return 0;
    
    
}
