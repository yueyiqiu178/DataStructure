#include<iostream>
#define N 100

using namespace std;



struct ListNode{
           
     ListNode *link;
     bool tag;
     
     union{
       char data;    
       ListNode *dlink;    
           };
        
        }; 
        
 struct Stack{
       ListNode *stackarray[N];
       int sp;
       
       
       };       
Stack s;


     
int push(Stack *,ListNode *);
ListNode* pop(Stack *);
int isempty(Stack *); 
int isfull(Stack *);  
ListNode* create(char []);
ListNode* listList(ListNode*);

        
int main(void){
    s.sp=-1;  
    
    
    ListNode* h=NULL;
    cout<<"請輸入廣義串列:";
    char input[50];
    cin>>input;
    h=create(input);
    
    listList(h);
    
     system("pause");
     return 0;
    
    
}


ListNode* create(char string[] ){
          ListNode *p=new ListNode;
          ListNode *q;
          int i=0;
          char x;
          x=string[i++];
          
          do{
              switch(x){
                  case '(':      
                        x=string[i++];
                        p->tag=true;
                        if(x==')'){
                              p->dlink=NULL;    
                              if(!isempty(&s))     
                                 x=string[i++];  
                                   
                                   }
                       else{
                            p->dlink=new ListNode;
                            
                            push(&s,p);
                            p=p->dlink;
                            } 
                        break;
                   case ')':
                        p->link=NULL;
                        p=pop(&s);
                           if(!isempty(&s))     
                           x=string[i++];   
                           break;
                           
                   case ',':
                        p->link=new ListNode;
                        p=p->link;
                        x=string[i++];
                        break;
                       
                   default:
                           p->tag=false;
                           p->data=x;
                           x=string[i++];            
                        
                        }        
                      
                      
                      }while(!isempty(&s));
                      
          
          q=p->dlink;
          free(p);
          
          return q;
          
          
          }
          
ListNode* listList(ListNode* ptr){
          if(ptr!=NULL){
                        
                 if(ptr->tag==true){ 
                                        
                        listList(ptr->dlink);
                        
                        }
                 else{
                      
                     cout<<ptr->data;
                      
                     
                      }        
                        
                 listList(ptr->link);     
                        
                         
                        }
                     
          }
          
                  
          
int push(Stack *p,ListNode *x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
ListNode* pop(Stack *p){
     if(isempty(p))
     return NULL;
     else
     return p->stackarray[p->sp--];     
     
      
     } 
     
int isempty(Stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
          
int isfull(Stack *p){
    if(p->sp==N-1)   
    return 1;
    else
    return 0;   
}
