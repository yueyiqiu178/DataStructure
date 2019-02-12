#include<iostream>
#include<string>
#define N 50
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='='))?1:0
#define operands(c) (((c)>=65 && (c)<=90)||((c)>=97&&(c)<=122))?1:0

using namespace std;

char s[10]={'1','2','3','4','5','6','7','8','9'};

struct Stack{
       int stackarray[N];
       int sp;
       
       
       };

void push(Stack *,int);
int pop(Stack *);
int isempty(Stack *);
int in_stack_priority(int);
int in_coming_priority(int);



       
int main(void){
      Stack stack1,stack2;
      stack1.sp=-1;
      stack2.sp==1;
      
      int temp=0;
      char input[N];
      cout<<"請輸入中序運算式:";
      cin>>input;
      int ptr=0;
      char k=input[ptr];
      while(k!='\0'){
                     
              
              ptr++;  
              k=input[ptr];     
                     
                     }
      
                    
      input[ptr]='#';
      input[ptr+1]='\0';
      
       push(&stack1,'#');
           
      int i=0;
      
     while(!isempty(&stack1)){
           char token=input[i++];                   
        if(operands(token)){       
             push(&stack2,token);
             }
             
        else if(token=='='){
            char u,v; 
            v=pop(&stack2);
            u=pop(&stack2);
            cout<<"LOAD "<<v<<endl;
            cout<<"STO "<<u<<endl; 
             
             }
        else{
        while(in_stack_priority(stack1.stackarray[stack1.sp])>in_coming_priority(token)){
                
                char u,v;
                char op;
                char w;
                v=pop(&stack2);
                u=pop(&stack2);
                op=pop(&stack1);
                w=s[temp];
                temp++; 
                cout<<"LOAD "<<u<<endl;
                cout<<op<<" "<<v<<endl;
                cout<<"STO "<<w<<endl;
                push(&stack2,w);
                                                                                         
              }
              if(in_stack_priority(stack1.stackarray[stack1.sp])<in_coming_priority(token))
                push(&stack1,token);
              else
                pop(&stack1);
              
              }                     
                            
                            
                        
                              }
           
         
           
           
            
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
    
    
    
int in_stack_priority(int c){
    char op[8]={'(',')','+','-','*','/','#','='};
    int prio[8]={0,6,2,2,4,4,-1,0};
    for(int i=0;i<8;i++){
        if(c==op[i])
           return prio[i];
           }
    
}


int in_coming_priority(int c){
    char op[8]={'(',')','+','-','*','/','#','='};
    int prio[8]={6,0,1,1,3,3,-1,0};
    for(int i=0;i<8;i++){
        if(c==op[i])
           return prio[i];
           }    
}


