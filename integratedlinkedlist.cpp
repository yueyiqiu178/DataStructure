#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        }; 
void addNewNode(Node **,int);
void listAll(Node *);
int lengthOfList(Node *);
void insertAfter(Node *,int,int);
void insertBefore(Node **,int,int);
void deleteNode(Node **,int);
void reverse(Node **head);
void concat(Node *,Node *,Node **);
void merge(Node *,Node *,Node **);
void concat2(Node *,Node *,Node **);
void MoveToRight(int,Node **,Node **);
void MoveToLeft(int,Node **,Node **);
int ListComp(Node *,Node *);
Node* function(Node *,Node *);
void sort(Node **);

int main(void){
    
    Node *head1=NULL;
    Node *head2=NULL;
    Node *head3=NULL;
    Node *head4=NULL;
    Node *head5=NULL;
    Node *head6=NULL;
    Node *head7=NULL;
    Node *head8=NULL;
    
    addNewNode(&head1,12);
    addNewNode(&head1,20);
    addNewNode(&head1,46);
    addNewNode(&head1,64);
    addNewNode(&head1,98);
    addNewNode(&head1,100);
    addNewNode(&head1,112);
    addNewNode(&head1,130);
    
    addNewNode(&head2,5);
    addNewNode(&head2,30);
    addNewNode(&head2,41);
    addNewNode(&head2,50);
    addNewNode(&head2,79);
    addNewNode(&head2,91);
    
    listAll(head1);
    listAll(head2);
    //concat(head1,head2,&head3);
    //listAll(head3);
     
   // merge(head1,head2,&head4);
    //concat2(head1,head2,&head3);
    //listAll(head3);
     
     
    addNewNode(&head4,23); 
    addNewNode(&head4,31); 
    addNewNode(&head4,37); 
    addNewNode(&head4,56); 
    addNewNode(&head4,37); 
    addNewNode(&head4,70);
    
    Node *p=head4,*l=NULL;
    
    MoveToRight(3,&p,&l);
    MoveToLeft(1,&p,&l);
    cout<<p->data<<" "<<l->data<<" "<<l->link->data<<endl;   
     
    
    addNewNode(&head5,23);
    addNewNode(&head5,31);
    addNewNode(&head5,37);
    addNewNode(&head5,56);
    addNewNode(&head5,25);
    
    
    addNewNode(&head6,23);
    addNewNode(&head6,31);
    addNewNode(&head6,37);
    addNewNode(&head6,56);
    addNewNode(&head6,25);
    addNewNode(&head6,98);
     
     
    cout<<ListComp(head5,head6)<<endl; 
    
    
    addNewNode(&head7,12);
    addNewNode(&head7,20);
    addNewNode(&head7,46);
    addNewNode(&head7,64);
    addNewNode(&head7,98);
    addNewNode(&head7,100);
    addNewNode(&head7,112);
    addNewNode(&head7,130);
    
    addNewNode(&head8,5);
    addNewNode(&head8,30);
    addNewNode(&head8,41);
    addNewNode(&head8,50);
    addNewNode(&head8,79);
    addNewNode(&head8,91);
    listAll(head7);
    listAll(head8);        
    Node *head9=NULL;
    
    head9=function(head7,head8);
    listAll(head9);
    
    Node *head10=NULL;
    addNewNode(&head10,5);
    addNewNode(&head10,30);
    addNewNode(&head10,41);
    addNewNode(&head10,50);
    addNewNode(&head10,79);
    addNewNode(&head10,91);
    
    listAll(head10);
    sort(&head10);
    listAll(head10);
    
     
            
     system("pause");        
     return 0;
    
}


int ListComp(Node *x,Node *y){
    
       int r=0;
       
       while(r==0&&x!=NULL&&y!=NULL){
           if((x->data)<(y->data))                          
                r=-1;
           else if((x->data)>(y->data))                        
                 r=1;
           else{
                x=x->link;
                y=y->link;
                
                }                                                               
                                     }
      if(r==0){
          if(x!=NULL)
            r=1;
          else if(y!=NULL)
            r=-1;                   
               }
               
      return r;
    
    
    }



void MoveToRight(int n,Node **p,Node **l){
     
     Node *r;
     
     while(n>0&&*p!=NULL){
           r=*l;              
           *l=*p;              
           *p=(*p)->link;
           (*l)->link=r;
           n--;              
                         
                         }
     
     if(n>0)
     cout<<"Error!!位移空間不足"<<endl;
     
     
     }

void MoveToLeft(int n,Node **p,Node **l){
     
      Node *r;
      while(n>0&&*l!=NULL){
              r=*p;
              *p=*l;
              *l=(*l)->link;
              (*p)->link=r;
              n--;               
              }
       
       if(n>0)
     cout<<"Error!!位移空間不足"<<endl;
       
     
     }


void concat(Node *root1,Node *root2,Node **root3){
     Node *ptr;
     
     if(root1==NULL){
                     
          *root3=root2;           
                     
                     }
     else{
          
          *root3=root1;
          if(root2!=NULL){
               ptr=root1;           
               while(ptr->link!=NULL) 
                    ptr=ptr->link;
                          
               ptr->link=root2;           
                                                  
                          }
           
          }

     }
     
void concat2(Node *root1,Node *root2,Node **root3){
     if(root1==NULL){
          *root3=root2;           
                     }
     else{
          Node *p,*q,*r;
          p=root1;
          q=root2;
          while(q!=NULL){
             r=p->link;            
             p->link=q;
             p=q;
             q=r;                                   
                         }
          *root3=root1;               
               
          }                
     
     
     
     }    
     
     


void merge(Node *x,Node *y,Node **z){
     
     Node *head,*tail;
     head=tail=new Node;
     while(x!=NULL&&y!=NULL){
                                  
            if((x->data)<=(y->data)){                        
                  tail->link=x;
                  tail=x;
                  x=x->link;}
            else{
                tail->link=y; 
                tail=y;
                y=y->link;
                 }                         
                                     }
     
          if(x!=NULL)
            tail->link=x;
           else
            tail->link=y;
            
            *z=head->link;
            free(head); 
     
     
     }

Node* function(Node *x,Node *y){
      
      if(x==NULL)
       return y;
       else{
            
            Node *z=new Node;
            z->data=x->data;
            z->link=function(x->link,y);
            return z;
            
            }
      
      
      }


void sort(Node **head){
     Node *list1_head,*list1_tail;
     Node *list2_head,*list2_tail;
     Node *ptr=*head;
     
     list1_head=list1_tail=new Node;
     list2_head=list2_tail=new Node;
     
     while(ptr!=NULL){
                      
          list1_tail->link=ptr;
          list1_tail=ptr;
          ptr=ptr->link;
                      
          list2_tail->link=ptr;
          list2_tail=ptr;
          ptr=ptr->link;
                      
                      
                      }
                      
        list1_tail->link=list2_head->link;
        *head=list1_head->link;
        
        delete(list1_head);
        delete(list2_head);
     
     
     }


void addNewNode(Node **ptr,int x){
     Node *pNewNode=new Node;
     pNewNode->data=x;
     pNewNode->link=NULL;
     
     if(NULL==(*ptr)){
     (*ptr)=pNewNode;}
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->link!=NULL){
     pTailNode=pTailNode->link;
     }
     pTailNode->link=pNewNode;
     
     }
     }
     
     
void listAll(Node *ptr){
     while(ptr!=NULL){ 
     cout<<ptr->data<<"  ";
     ptr=ptr->link;
     } 
      
     cout<<endl; 
}
     
int lengthOfList(Node *ptr){
    int count=0;
    if(ptr==NULL)
    return 0;
    else{
    while(ptr!=NULL) {
     count++;
     ptr=ptr->link;
     }
     
     return count;
     }
     }
     
void insertAfter(Node *ptr,int x,int y){
     if(ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else{
        while(ptr->data!=x&&ptr->link!=NULL) 
          ptr=ptr->link;
          
          if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=ptr->link;
          ptr->link=pNewNode;}
          else
               cout<<"找不到該節點"<<endl; 
               
               
          }
     
     
     }
     
     
void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=*ptr;
          *ptr=pNewNode;
          
          }
     else{
        while(newptr->data!=x&&newptr->link!=NULL){ 
          r=newptr;
          newptr=newptr->link;}
          
          if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=r->link;
          r->link=pNewNode;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     }
 
void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          
          (*ptr)=(*ptr)->link;
                  
          }   
     else{
        while(newptr->data!=x&&newptr->link!=NULL){ 
          r=newptr;
          newptr=newptr->link;}
          
          if(newptr->data==x){
            r->link=newptr->link;
            newptr->link==NULL;
            newptr=r->link;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     
     
     
     }
 
     
     
void reverse(Node **head){
      Node *ptr,*tmp;
      ptr=(*head);
      tmp=NULL;
      while(ptr->link!=NULL){
           (*head)=ptr->link;          
              ptr->link=tmp;
              tmp=ptr;
              ptr=(*head);              
                             }
        ptr->link=tmp;                     
      
     
     }
     

