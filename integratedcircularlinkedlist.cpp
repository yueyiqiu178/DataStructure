#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node *link;   
        }; 
        
void addNewNode(Node **,int);      
void listAll(Node *);
int length(Node *);
void insertAfter(Node *,int,int);
void insertBefore(Node **,int,int);
void deleteNode(Node **,int);
void reverse(Node **);
void copy(Node *,Node **);
void concat(Node *,Node *);
void concat2(Node *,Node *,Node **);
        
int main(void){
    
     Node *head=NULL;
     addNewNode(&head,15);
     addNewNode(&head,18);
     addNewNode(&head,59);
     addNewNode(&head,34);
     addNewNode(&head,23);
     addNewNode(&head,98);
     addNewNode(&head,100);
     addNewNode(&head,47);
     addNewNode(&head,68);
     addNewNode(&head,84);
     addNewNode(&head,58);
     addNewNode(&head,13);
     addNewNode(&head,78);
     addNewNode(&head,91);
     addNewNode(&head,17);
     addNewNode(&head,73);
     int n;
     Node *p,*tmp;
     Node *ptr=head;
     cout<<"請輸入間格數:";
     cin>>n;
     while(ptr->link!=ptr){
        for(int i=2;i<=n;i++){                
          p=ptr;
          ptr=ptr->link;}
                           
        tmp=ptr;
        ptr=ptr->link;
        p->link=ptr;
        free(tmp);                   
                           }
     
     cout<<ptr->data<<endl;
     
    
     Node *head2=NULL;
     Node *head3=NULL;
     
     addNewNode(&head2,50);
     addNewNode(&head2,31);
     addNewNode(&head2,24);
     addNewNode(&head2,38);
     
     addNewNode(&head3,41);
     addNewNode(&head3,78);
     addNewNode(&head3,90);
     listAll(head2);
     listAll(head3);
     concat(head2,head3);
     listAll(head2);
     
     Node *head4=NULL;
     Node *head5=NULL;
     Node *head6=NULL;
     addNewNode(&head4,50);
     addNewNode(&head4,11);
     addNewNode(&head4,29);
     addNewNode(&head4,40);
     addNewNode(&head4,39);
     addNewNode(&head4,10);
     addNewNode(&head4,44);
     addNewNode(&head4,400);
     addNewNode(&head4,10);
     addNewNode(&head4,44);
     addNewNode(&head4,900);
     
     
     addNewNode(&head5,41);
     addNewNode(&head5,78);
     addNewNode(&head5,90);
     addNewNode(&head5,71);
     addNewNode(&head5,74);
     addNewNode(&head5,100);
     listAll(head4);
     listAll(head5);
     concat2(head4,head5,&head6);
     
     listAll(head6);
     reverse(&head6);
     listAll(head6);
    
     system("pause");
     return 0;
    
}


void addNewNode(Node **ptr,int x){
     Node *pNewNode=new Node;
     pNewNode->data=x;
     pNewNode->link=NULL;    
          if(*ptr==NULL){      
             *ptr=pNewNode;
              pNewNode->link=pNewNode;}
          else{
     Node *pTailNode=*ptr;
     while(pTailNode->link!=*ptr)
          pTailNode=pTailNode->link;
                
          pTailNode->link=pNewNode;
          pNewNode->link=*ptr; 
          
                }
                }
                
                
void listAll(Node *ptr){
      Node *pTail=ptr;
      if(ptr==NULL)
      cout<<"空串列"<<endl;
      else{
     while(pTail->link!=ptr){
     cout<<pTail->data<<"  ";
     pTail=pTail->link;
     }
     
     cout<<pTail->data<<"  ";
     
     cout<<endl;
}
     
     }
     
int length(Node *ptr){
     int count=0;
     Node *lkk=ptr;
     if(ptr==NULL)
     return 0;
     else{
     while(lkk->link!=ptr){
     count++;
     lkk=lkk->link;
}
     count++;
     return count;
     }
     }
     
     
void insertAfter(Node *ptr,int x,int y){
     
     if(ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else{
        while(ptr->data!=x&&ptr->link!=ptr) 
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
     Node *head=*ptr;
     Node *temp=*ptr;
     if(*ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(head->data==x){
          Node *pTail=*ptr;
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=*ptr;
          while(pTail->link!=head)
           pTail=pTail->link;
          
          pTail->link=pNewNode;
          *ptr=pNewNode;
          
          
          }
     else{
        while(head->data!=x&&head->link!=temp){ 
          r=head;
          head=head->link;}
          
          if(head->data==x){
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
       Node *pTail=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          while(pTail->link!=*ptr)
             pTail=pTail->link;             
          
          (*ptr)=(*ptr)->link;
           pTail->link=*ptr;
                  
          }   
     else{
        while(newptr->data!=x&&newptr->link!=*ptr){ 
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
      Node *newptr=*head;
      Node *ptr,*tmp;
      ptr=*head;
      tmp=NULL;
      while(ptr->link!=newptr){
           (*head)=ptr->link;          
              ptr->link=tmp;
              tmp=ptr;
              ptr=(*head);              
                             }
        ptr->link=tmp;                     
        newptr->link=*head;
     
     }
     
     
void copy(Node *root1,Node **root2){
     
     if(root1!=NULL){
          Node *ptr=root1;
          Node *head,*tail;
          head=tail=new Node;
          
          do{
             tail->link=new Node;
             tail=tail->link;                     
             tail->data=ptr->data;
             ptr=ptr->link;                     
                                  
                                  }while(ptr!=root1);
                                  
          tail->link=head->link;                                  
          tail=head->link;
          free(head);
          *root2=tail;  
                                                      
                     }
      else{
           *root2=root1;
           }        
                   
     }
     
void concat(Node *x,Node *y){
     Node *ptr=x;
     while(ptr->link!=x)
         ptr=ptr->link;
     
     ptr->link=y;
     
     ptr=y;
      while(ptr->link!=y)
       ptr=ptr->link;
       
      ptr->link=x;
     }


     
void concat2(Node *root1,Node *root2,Node **root3){
     if(root1==NULL){
          *root3=root2;           
                     }
     else{
          Node *p,*q,*r;
          p=root1;
          q=root2;
          
          do{
             r=p->link;            
             p->link=q;
             p=q;
             q=r;                                   
                         }while(q!=root1&&q!=root2);
                         
          if(q==root1){
             while(p->link!=root2)         
               p=p->link;
                  
                  p->link=root1;
                        
                        }
          *root3=root1;               
               
          }                
     
     
     
     }    
     
