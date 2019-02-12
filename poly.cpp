#include<iostream>
#include<math.h>

using namespace std;



struct PolyNode{
           
    float coef;
    int exp;
    PolyNode *link;
        
        }; 
        
        
void createPolyA(PolyNode **);
void createPolyB(PolyNode **);
void listAll(PolyNode *);
PolyNode* newTerm(float,int);
PolyNode* padd(PolyNode *,PolyNode *);
PolyNode* search(int,PolyNode * ,PolyNode *&);
void deleteNode(PolyNode *);
void insert(float,int,PolyNode *);
PolyNode* pmul(PolyNode *,PolyNode *);
float evaluate(PolyNode *,float);

        
int main(void){
    
     PolyNode *head_a=NULL;
     PolyNode *head_b=NULL;
     createPolyA(&head_a);
     createPolyB(&head_b);
     cout<<"多項式A為:";
     listAll(head_a);
     cout<<"多項式B為:";
     listAll(head_b);
     
     PolyNode *newpoly;
     newpoly=padd(head_a,head_b);
     cout<<"多像式相加結果為:";
     listAll(newpoly);
     cout<<endl;
     PolyNode *mulpoly;
     mulpoly=pmul(head_a,head_b);
     cout<<"多像式相乘結果為:";    
     listAll(mulpoly);
     cout<<endl;
     
     
     cout<<evaluate(mulpoly,-1)<<endl;
     cout<<evaluate(head_a,-1)<<endl;
     
    
     system("pause");
     return 0;
    
    
}



PolyNode*  padd(PolyNode* x,PolyNode* y){
           PolyNode *p,*q,*head,*tail,*final;
           
           float c;
           p=x;q=y;
           tail=new PolyNode;
           head=tail;
           
           while(p!=NULL&&q!=NULL){
                if(p->exp==q->exp){                   
                if((c=p->coef+q->coef)!=0){
                        tail->link=newTerm(c,p->exp);                    
                            tail=tail->link;     }
                   p=p->link;        
                   q=q->link;   
                                   }
                 else if((p->exp)<(q->exp)){
                 tail->link=newTerm(q->coef,q->exp);
                 tail=tail->link;
                 q=q->link;
                 }
                 
                 else{
                      tail->link=newTerm(p->coef,p->exp);
                      tail=tail->link;
                      p=p->link;
                      }
                      
                      
                                   }
                                   
                                   
           while(p!=NULL){
                 tail->link=newTerm(p->coef,p->exp);
                 tail=tail->link;
                 p=p->link;        
                          }
                          
            while(q!=NULL){
                 tail->link=newTerm(q->coef,q->exp);
                 tail=tail->link;
                 q=q->link;         
                          }
                          
           tail->link=NULL;
           final=head->link;
           free(head);
           return final;
           
           
           }
           
void createPolyA(PolyNode **head){
     PolyNode *ptr;
     ptr=new PolyNode;
     *head=ptr;
     
     ptr->coef=1;
     ptr->exp=4;
     ptr->link=new PolyNode;
     ptr=ptr->link;
     
     ptr->coef=2;
     ptr->exp=3;
     ptr->link=new PolyNode;
     ptr=ptr->link;
     
     
     ptr->coef=3;
     ptr->exp=2;
     ptr->link=new PolyNode;
     ptr=ptr->link;
     
     ptr->coef=1;
     ptr->exp=0;
     ptr->link=NULL;
}


void createPolyB(PolyNode **head){
     PolyNode *ptr;
     ptr=new PolyNode;
     *head=ptr;
     
    
   
     
     ptr->coef=1;
     ptr->exp=3;
     ptr->link=new PolyNode;
     ptr=ptr->link;
     
     ptr->coef=4;
     ptr->exp=2;
     ptr->link=new PolyNode;
     ptr=ptr->link;
     
     
     
     ptr->coef=1;
     ptr->exp=1;
     ptr->link=NULL;
     
}


void listAll(PolyNode *ptr){
       while(ptr!=NULL){
     cout<<ptr->coef<<"X"<<ptr->exp<<" ";
     ptr=ptr->link;
     }
     cout<<endl;
     
     }
     
PolyNode* newTerm(float c,int e){
          PolyNode *p=new PolyNode;
          p->coef=c;
          p->exp=e;
          return p;
          
          }
          
          
PolyNode* pmul(PolyNode *x,PolyNode *y){
          PolyNode *p,*q,*r,*head,*pre=NULL;
          int e;
          float c;
          
          head=new PolyNode;
          head->link=NULL;
          head->exp=100;
          r=head;
          for(p=x;p!=NULL;p=p->link)
          for(q=y;q!=NULL;q=q->link){
               r=head;                      
               c=(p->coef)*(q->coef);                     
               e=(p->exp)+(q->exp);   
               r=search(e,r,pre);
               
                                  
                if(e==r->exp){
                     r->coef+=c;                             
                     if(r->coef==0)                              
                       deleteNode(pre); 
                     
                                               
                                                   }                
                else{
                     
                     insert(c,e,r);
                     
                     }                     
                                     
                                     }
          
          p=head->link;
          free(head);
          return p;
          
          }
          
          
PolyNode* search(int e,PolyNode *ptr,PolyNode *&k){
          PolyNode *p,*before=NULL;
          p=ptr;
          
          while(p->link!=NULL&&(p->exp)>e){
                                           
               before=p;                            
               p=p->link;                            
                                           
                                           
                                           }
          
          //for(p=ptr;p->link!=NULL&&(p->exp)<e;p=p->link);
          k=before;
          return p;
          
          }
          
void insert(float c,int e,PolyNode *ptr){
     PolyNode *p=new PolyNode;
     p->coef=c;
     p->exp=e;
     p->link=NULL;
     if(ptr->link=NULL){
          ptr->link=p;   
                           }
      else{
           p->link=ptr->link;
           ptr->link=p;
           }                     
     }
     
void deleteNode(PolyNode *ptr){
     
     PolyNode *p;
     p=ptr->link;
     ptr->link=p->link;
     free(p);
     
     }
     
float evaluate(PolyNode *ptr,float x){
      
       PolyNode *q;
       q=ptr;
       float p;
       for(q=ptr,p=ptr->coef;q->link!=NULL;q=q->link){
                               
            p=p*pow(x,(q->exp)-(q->link->exp))+q->link->coef;                   
            
                               }
                               
            return p;
       
}

