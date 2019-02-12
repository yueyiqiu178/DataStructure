#include<iostream>
#define N 10
using namespace std;


struct stack{
       int stackarray[N];
       int sp;
       
       
       };


int push(stack *,int);
int pop(stack *);
void printstack(stack *);
int isempty(stack *);
int isfull(stack *);
void Enqueue(stack *,int);
void Dequeue(stack *,stack *,int *);
void printQueue(stack *,stack *);


int main(){
    stack stack1,stack2;
    stack1.sp=-1;
    stack2.sp=-1;
    int data;
    
    Enqueue(&stack1,10);
    Enqueue(&stack1,5);
    Dequeue(&stack1,&stack2,&data);
    printQueue(&stack1,&stack2);
    Enqueue(&stack1,15);
    Enqueue(&stack1,30);
    printQueue(&stack1,&stack2);
    Enqueue(&stack1,5);
    Enqueue(&stack1,78);
    Enqueue(&stack1,10);
    printQueue(&stack1,&stack2);
    //cout<<stack2.stackarray[0]<<" "<<stack2.stackarray[1]<<endl<<stack2.sp<<endl;
    
    system("pause");
       return 0;
}



int push(stack *p,int x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
int pop(stack *p){
    
     
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


void Enqueue(stack *p1,int x){
         
         push(p1,x);

     }
     
     
void Dequeue(stack *p1,stack *p2,int *x){
     if(isempty(p2)){
          if(isempty(p1))
          cout<<"¦î¦C¬OªÅªº"<<endl;           
          else        
          while(!isempty(p1)){  
               int y=pop(p1);      
                push(p2,y);     
                     }
                     }
     
     *x=pop(p2);
     
     }
     
     
void printQueue(stack *p1,stack *p2){
      
      if(!isempty(p2))
      for(int i=p2->sp;i>=0;i--)
      cout<<p2->stackarray[i]<<" ";
      
      
      for(int i=0;i<=p1->sp;i++)
      cout<<p1->stackarray[i]<<" ";
      
      cout<<endl;
     
     }
