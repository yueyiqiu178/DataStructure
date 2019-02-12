#include<iostream>
#define N 100
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/'))?1:0
#define operands(c) ((c)>='0' && (c)<='9')?1:0


using namespace std;

typedef struct{
       int stackarray[N];
       int sp;
       
       
       }Stack;
       

int transform(char*,char*,Stack*);
void push(Stack *,int);
void pop(Stack *,int *);
int in_stack_priority(int);
int in_coming_priority(int);
int evaluate(char *,Stack *);
int cal(int,int,char);
int pop2(Stack *);

                
int main(void){
    Stack s;
    s.sp=-1;
    
    char input[N];
    char final[N];
    cout<<"請輸入中序運算式";
    cin>>input;
    transform(input,final,&s);
    cout << "中序式 => " << input << "  後序式=> " <<final<<endl;
    cout<<"計算出來的值 => "<<evaluate(final,&s)<<endl;
    
    
    
    system("pause");
    return 0;
    
    }
    
    
int transform(char *infix,char *postfix,Stack *p){
    int i=0,j=0;
    int element;
    char token;
    token=infix[i];
    
    while(token!='\0'){
                              
        if(operands(token))                      
             postfix[j++]=token;                
        else if(token=='(')                    
             push(p,token);
        else if(token==')'){
             while(p->sp>=0){
             pop(p,&element);
             
             if(element=='(')
             break;
             postfix[j++]=element;
             }  
             }
        else if(operator(token)){
             while(p->sp!=-1){
                element=p->stackarray[p->sp];
                if((in_coming_priority(token))<=(in_stack_priority(element))){
                pop(p,&element);
                postfix[j++]=element;                                        
                }
                else
                break;
             }
        push(p,token);                           
} 
i++;
token=infix[i];
} 

    while(p->sp!=-1){
        pop(p,&element);
        postfix[j++]=element;            
                    }
                    
        postfix[j]='\0';


}

void push(Stack *p,int x){
     
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
void pop(Stack *p,int *x){
     
     
     *x=p->stackarray[p->sp];     
     p->sp--;
      
     } 
     


int in_stack_priority(int c){
    char op[5]={'(','+','-','*','/'};
    char prio[5]={0,1,1,2,2};
    for(int i=0;i<5;i++){
        if(c==op[i])
           return prio[i];
           }
    
}


int in_coming_priority(int c){
    char op[5]={'(','+','-','*','/'};
    char prio[5]={4,1,1,2,2};
    for(int i=0;i<5;i++){
        if(c==op[i])
           return prio[i];
           }    
}


int evaluate(char *postfix,Stack *p){
    char token;
    int i=0;
    int result;
    int a,b;
    token=postfix[i];
    char elem1[5],elem2[5];
    
    while(token!='\0'){
         if(operands(token))
         push(p,token-48);
         else if(operator(token))  {         
         a=pop2(p);
         b=pop2(p);
         
         result=cal(b,a,token);
         push(p,result);
                     }
           i++;
           token=postfix[i];
                     
                     }
         
         pop(p,&result);
         
         return result;            
                     
}


int cal(int x,int y,char c){
    
    
    switch(c){
    
    case '+':
               return x+y;
               break;
    case '-':
               return x-y;
               break; 
    case '*':
               return x*y;
               break; 
    case '/':
               return x/y;
               break; 
}
    
}



     
int pop2(Stack *p){
     
    
     return p->stackarray[p->sp--];     
    
      
     } 
     
