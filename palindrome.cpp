#include<iostream>
#define N 50


using namespace std;

struct Stack{
       int stackarray[N];
       int sp;
       
       
       };

void push(Stack *,int);
int pop(Stack *);
int isempty(Stack *);


       
int main(void){
      Stack stack;
      stack.sp=-1;
      
      char input[N];
      char output[N];
      cout<<"�п�n�ˬd���r��:";
      cin>>input;
      char k;
      int ptr=0;
      k=input[ptr];
      while(k!='\0'){
        push(&stack,k);     
              ptr++;  
              k=input[ptr];   
                   
                   }
       
       ptr=0;
     while(!isempty(&stack)){
             output[ptr++]=pop(&stack);     
                            
                             }
                           
        output[ptr]='\0';
        cout<<"��r��:"<<input<<endl;
        cout<<"�����r��:"<<output<<endl;
        
        bool flag=true;
        
        for(int i=0;i<ptr;i++){ 
            if(input[i]!=output[i])
             flag=false;
            
            } 
            
          if(flag==true)
          cout<<"���r��O�^��"<<endl;
          else  
         cout<<"���r�ꤣ�O�^��"<<endl;
           
    system("pause");
    return 0;
    
    }
    
    
void push(Stack *p,int x){
     
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
int pop(Stack *p){
     
     
     return p->stackarray[p->sp--];  
      
     }   
    
int isempty(Stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }    
    
    
    




