#include<iostream>
#define MAX_STACK 100

typedef int ITEM_TYPE;
typedef enum boolean{FALSE,TRUE}BOOLEAN;
typedef struct stack_type{
        ITEM_TYPE item[MAX_STACK];
        int top;
        
        }STACK_TYPE;

using namespace std;


void create_stack(STACK_TYPE *stack);
void destroy_stack(STACK_TYPE *stack);
BOOLEAN empty_stack(STACK_TYPE *stack);
BOOLEAN full_stack(STACK_TYPE *stack);
void push(STACK_TYPE *stack,ITEM_TYPE new_item);
void pop(STACK_TYPE *stack,ITEM_TYPE *old_item);


int main(){
    
    
    
    
 system("pause");
 return 0;   
    
}


void create_stack(STACK_TYPE *stack){
      stack->top=0;
     
     }
     
     
void destroy_stack(STACK_TYPE *stack){
        free(stack);
     }

BOOLEAN empty_stack(STACK_TYPE *stack){
        if(stack->top==0)
        return TRUE;
        else
        return
        FALSE;
        
        }
        
BOOLEAN full_stack(STACK_TYPE *stack){
        if(stack->top==MAX_STACK)
        return TRUE;
        else
        return FALSE;
        }
        
void push(STACK_TYPE *stack,ITEM_TYPE new_item){
       
       if(!full_stack(stack)){
       stack->item[stack->top]=new_item;
       stack->top++;}
       else
       cout<<"堆疊已滿"<<endl; 
     }
     
void pop(STACK_TYPE *stack,ITEM_TYPE *old_item){
     
     if(!empty_stack(stack)){
     stack->top--;
     *old_item=stack->item[stack->top];
     }
     else
     cout<<"堆疊已空"<<endl;
     }
