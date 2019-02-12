#include<iostream>


using namespace std;


struct tTreeNode{
        
     int value;   
     tTreeNode *left;
     tTreeNode *right; 
     bool leftthread;
     bool rightthread;
     
        }; 


void TBT_insert(tTreeNode *,int);
tTreeNode* insuc(tTreeNode *);
void inorder(tTreeNode *);
void insertRight(tTreeNode *,tTreeNode *);


int main(void){
    tTreeNode head;
    head.leftthread=true;
    head.rightthread=false;
    head.left=&head;
    head.right=&head;
    tTreeNode *temp=new tTreeNode;
    temp->value=87; 
    
    TBT_insert(&head,25);
    
    TBT_insert(&head,50);
    /*TBT_insert(&head,40);
    TBT_insert(&head,10);
    TBT_insert(&head,23);
    TBT_insert(&head,30);
    TBT_insert(&head,60);
    TBT_insert(&head,55);
    TBT_insert(&head,70);*/
    insertRight(head.left,temp);
    
    
    inorder(&head);
    
    
    system("pause");
    return 0;
}



void TBT_insert(tTreeNode *head,int x){
       tTreeNode *ptr;
       tTreeNode *p=new tTreeNode;
       p->leftthread=true;
       p->rightthread=true;
       p->value=x;
    
     
     if(head->leftthread==true){
      
       p->right=head;
       p->left=head;                         
       head->left=p;
       head->leftthread=false;
       
       }
     else{
          ptr=head->left;
          
          while(ptr!=head){
          
          
          if((ptr->value)>x){
              if(ptr->leftthread==false)             
                   ptr=ptr->left;        
              else{             
                  p->left=ptr->left;        
                  p->right=ptr;         
                  ptr->leftthread=false;
                  ptr->left=p; 
                  break;        
                           }
                           }
          
                
                 else if(ptr->value<x){
                                   
               if(ptr->rightthread==false){
                  ptr=ptr->right;}
               else{
                   p->right=ptr->right;
                   p->left=ptr;
                   ptr->rightthread=false;
                   ptr->right=p;
                   break;
                   }
                                   }
               }
               
          }     
          
     }
     
     
void inorder(tTreeNode *head){
     tTreeNode *ptr=head;
     do{
          ptr=insuc(ptr);     
          if(ptr!=head)     
            cout<<"Visit"<<ptr->value<<endl;   
               
               }while(ptr!=head);
               
               
}               
               
tTreeNode* insuc(tTreeNode *s){
           tTreeNode* t=s->right;
           if(!s->rightthread)
           while(!t->leftthread)
              t=t->left;              
                                 
           return t;                      
           
           
           }
     
     
void insertRight(tTreeNode *s,tTreeNode *t){
     
       tTreeNode *p;
       t->rightthread=s->rightthread;
       t->right=s->right;
       t->leftthread=true;
       t->left=s;
       s->rightthread=false;
       s->right=t;
       
       if(!t->rightthread){
               p=insuc(t);            
               p->left=t;              
                           }
 
     }
     



     
     
     
     

