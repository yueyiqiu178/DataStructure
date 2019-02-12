#include<iostream>

using namespace std;
struct Node{
       int data;
       Node *llink;
       Node *rlink;
       
};


void addNewNode(Node **,int);      
void listAll(Node *);
int lengthOfList(Node *);
void insertAfter(Node *,int,int);
void insertBefore(Node **,int,int);
void deleteNode(Node **,int);
void concat(Node *,Node *,Node **);

        


int main(void){
    
     Node *head1=NULL;
    Node *head2=NULL;
    Node *head3=NULL;
    Node *head4=NULL;
    
    addNewNode(&head1,12);
    addNewNode(&head1,20);
    addNewNode(&head1,46);
    addNewNode(&head1,64);
    addNewNode(&head1,98);
    
    addNewNode(&head2,5);
    addNewNode(&head2,30);
    addNewNode(&head2,41);
    addNewNode(&head2,50);
    addNewNode(&head2,79);
    addNewNode(&head2,91);
    
    listAll(head1);
    listAll(head2);
                      
    concat(head1,head2,&head3);
    
    listAll(head3);
    
    system("pause");
    return 0;
    
}

void concat(Node *root1,Node *root2,Node **root3){
               Node *ptr;    
           if(root1==NULL){
                 *root3=root2;          
                           }        
           else if(root2!=NULL){
               ptr=root1->llink;
               root1->llink=root2->llink;
               ptr->rlink=root2;
               root2->llink=ptr;
               root1->llink->rlink=root1;
                
               *root3=root1; 
                }
           else
                *root3=root1;             

}

void addNewNode(Node **ptr,int x){
     Node *pNewNode=new Node;
     pNewNode->data=x;
     pNewNode->llink=NULL;
     pNewNode->rlink=NULL;
     
     if(NULL==(*ptr)){
     (*ptr)=pNewNode;
     (*ptr)->llink=(*ptr);
     (*ptr)->rlink=(*ptr);
     }
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->rlink!=(*ptr)){
     pTailNode=pTailNode->rlink;
     }
     pTailNode->rlink=pNewNode;
     pNewNode->rlink=*(ptr);
     pNewNode->llink=pTailNode;
     (*ptr)->llink=pNewNode;
     }
     }
     
     
void listAll(Node *p){
     if(p==NULL)
     cout<<"空串列"<<endl;
     else{ 
     Node *ptr=p;
     while(ptr->rlink!=p){ 
     cout<<ptr->data<<"  ";
     ptr=ptr->rlink;
     } 
      
     cout<<ptr->data<<endl; 
     }
}


int lengthOfList(Node *ptr){
    Node *p=ptr;
    int count=0;
    if(ptr==NULL)
    return 0;
    else{
    while(p->rlink!=ptr) {
     count++;
     p=p->rlink;
     }
     count++;
     return count;
     }
     }
     
     
     
 void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
       Node *s=(*ptr)->rlink;
       Node *tail=*ptr;
      
        
     if(newptr==NULL){
        cout<<"此串列為空串列,找不到該節點"<<endl;}
     else if(newptr->llink==newptr&&newptr->rlink==newptr&&newptr->data==x){
        free(newptr);  
         *ptr=NULL; 
          
          }   
     else if(newptr->data==x){
          while(tail->rlink!=*ptr)
             tail=tail->rlink;
             
          Node *temp=*ptr;
          (*ptr)=(*ptr)->rlink;
          free(temp);
          (*ptr)->llink=tail;       
          tail->rlink=(*ptr);         
          }    
     else{
        while(newptr->data!=x&&newptr->rlink!=tail->rlink){ 
             r=newptr;
             newptr=newptr->rlink;
             s=s->rlink;
          }
          if(newptr->data==x&&s==tail->rlink){
              free(newptr);
              r->rlink=s;
              s->llink=r;                                
                                              
                                              }
          else if(newptr->data==x){
            free(newptr);
            r->rlink=s;
            s->llink=r;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     
     
     
     } 
     
     
     
void insertAfter(Node *p,int x,int y){
     Node *ptr=p;
     Node *pre;
     if(ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else{
        while(ptr->data!=x&&ptr->rlink!=p){ 
          pre=ptr;
          ptr=ptr->rlink;
          }
          if(ptr->data==x&&ptr->rlink==p){
              Node *pNewNode=new Node;
              pNewNode->data=y;
              
              ptr->rlink=pNewNode;
              pNewNode->llink=ptr;
              pNewNode->rlink=p;
              p->llink=pNewNode;                          
                                         
                                         }
          else if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=ptr->rlink;
          ptr->rlink->llink=pNewNode;
          ptr->rlink=pNewNode;
          pNewNode->llink=ptr;
          }
          else
               cout<<"找不到該節點"<<endl; 
               
               
          }
     
     
     }  
     
     
     
void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *head=*ptr;
     if(*ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(head->data==x){
          Node *pTail=*ptr;
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=*ptr;
          (*ptr)->llink=pNewNode;
          while(pTail->rlink!=head)
           pTail=pTail->rlink;
          
          pTail->rlink=pNewNode;
          pNewNode->llink=pTail;
          *ptr=pNewNode;
          
          
          }
     else{
        while(head->data!=x&&head->rlink!=(*ptr)){ 
          r=head;
          head=head->rlink;}
          
          if(head->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=head;
          head->llink=pNewNode;
          r->rlink=pNewNode;
          pNewNode->llink=r;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     }
     
     
void linkRecover(Node *head,Node *last){
     
     Node *leftmost=head;
     Node *rightmost=last;
     
             
     while(leftmost->rlink!=NULL&&leftmost->rlink->llink==leftmost)        
      leftmost=leftmost->rlink;
     
     if(leftmost!=rightmost){
        
        while(rightmost!=leftmost->rlink&&rightmost->llink->rlink==rightmost)                     
             rightmost=rightmost->llink;           
        
        if(leftmost->rlink==rightmost)
           rightmost->llink=leftmost;
        else
           leftmost->rlink=rightmost;
                             
                             }
     
     
     }

