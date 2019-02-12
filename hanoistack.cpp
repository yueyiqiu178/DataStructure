#include<iostream>
#define N 10000
using namespace std;

struct stack{
       int stackarray[N];
       int sp;
       
       
       };
 stack s;
 stack p;
        
 
int push(stack *,int);
int pop(stack *);
void printstack(stack *);
int isempty(stack *);
int isfull(stack *); 
void move(int,char,char,char); 
int fact(int n);
       
int main(){
    
    s.sp=-1;  
    p.sp=-1;
    
    
    move(3,'A','B','C');
    cout<<fact(6)<<endl;
    
   
    system("pause");
     return 0;
     
     
     }

void move(int n,char source,char temp,char destination){
     
      
      L0:
              if(n>0){
              push(&s,1);push(&s,n);push(&s,source);push(&s,temp);push(&s,destination);
              n--;swap(temp,destination);
              goto L0;
     L1:      cout<<"Move disk"<<n<<" from "<<source<<" to "<<destination<<endl;
              push(&s,2);push(&s,n);push(&s,source);push(&s,temp);push(&s,destination);
              n--; swap(source,temp);
              goto L0;
     L2:   ;   
     
     }

     if(!isempty(&s)){
                      
         destination=pop(&s);
         temp=pop(&s);     
         source=pop(&s);
         n=pop(&s);
         switch(pop(&s)){
            case 1:goto L1;       
            case 2:goto L2;       
                   }   
                   
                   
                             
                      
                      }

}

int fact(int n){
    int r;
    
   L0:
        if(n>0){
                push(&p,1);push(&p,n);
                n--;
                goto L0;
              
             L1: 
              r=r*n;    
                }
         else
         r=1;
         
       
          
       
         if(!isempty(&p)){
              n=pop(&p);
              switch(pop(&p)){            
              case 1:goto L1;break;  
              }              
                          }
         else
          return r;
    
    
        
    
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


void swap(char &p,char &q){
     
     char t;
     t=p;
     p=q;
     q=t;
     
     
     
     }
 
 
 
