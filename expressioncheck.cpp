#include<iostream>
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/'))?1:0
#define operands(c) ((c)>='0' && (c)<='9')?1:0

using namespace std;

void prefixcheck(char []);

int main(){
    
    char input[20];
    cin>>input;
    
    prefixcheck(input);    
    
    
    
     
   system("pause");   
    return 0;
    
    
}


void prefixcheck(char x[]){
      
      int i=0;
      char token=x[i++];
      int rank=0;
      
      while(token!='\0'){
                         
          if(operator(token))  
              rank--;
          else
             rank++;
             
            token=x[i++]; 
            
             if(rank>0)
              break;
                 
              }
      
       if(rank==1&&token=='\0')
        cout<<"expression correct"<<endl;
       else
        cout<<"expression error"<<endl;
     
     
     }
    
