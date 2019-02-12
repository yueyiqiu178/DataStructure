#include<iostream>
#include<time.h>
#define M 100
using namespace std;


struct stack{
       int stackarray[M];
       int sp;
       
       
       };

stack bigstack;


int N=0;
int PrefixEval(char[]);
int get_next_token(char[]);
void createstack(stack *);
int push(stack *,int);
int pop(stack *);
int isempty(stack *);
int isfull(stack *);
int PostfixEval(char []);



int main(void){
    
    char input[5];
    cin>>input;
    cout<<input<<endl;
    
    cout<<"運算結果為"<<PrefixEval(input)<<endl; 
    
    system("pause");
    return 0;
    
    }
 
 
void createstack(stack *p){
     p->sp=-1;
     }  
 
 
int push(stack *p,int x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
int pop(stack *p){
     if(isempty(p))
     return 1;
     else
     return p->stackarray[p->sp--];     
     
      
     } 
     
int isempty(stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
     
int isfull(stack *p){
    if(p->sp==N-1)   
    return 1;
    else
    return 0;   
}
 
 
 

 
 
int PrefixEval(char s[]){
    int x=get_next_token(s);
    if(x==0)
    cout<<"結束"<<endl;  // +5*43
    else if(x==-1) 
    return PrefixEval(s)+PrefixEval(s);
    else if(x==-2)
    return PrefixEval(s)*PrefixEval(s);
    else
    return x;    
}
 
   
    
int get_next_token(char s[]){
    
   
      if(s[N]>=49&&s[N]<=57)
        return s[N++]-48; 
      if(s[N]=='+'){
        N++;
        return -1;} 
      if(s[N]=='*'){    
        N++;
        return -2;}
      if(s[N]=='\0'){
        N++;
        return 0;}  
    
}



int PostfixEval(char s[]){
    int x;
    createstack(&bigstack);
    x=get_next_token(s);
    while(x!=0){
        if(x>0)        
          push(&bigstack,x);      
         else if(x==-1){       
                int p=pop(&bigstack);
                int q=pop(&bigstack);
                push(&bigstack,p+q);
                
                }
         else if(x==-2){
                int p=pop(&bigstack);
                int q=pop(&bigstack);
                push(&bigstack,p*q); 
              }
              
        x=get_next_token(s);                     
                } 
                
                return pop(&bigstack);
}
