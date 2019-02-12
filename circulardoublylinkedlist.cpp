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
void reverse(Node **);
void ddelete(Node **,Node *);
        


int main(void){
    
    Node *head=NULL;
   
    int loopflag,choose;
    int a,b;
     while(loopflag){ 
            
            cout<<"(1)���J�@�s�`�I\n(2)�C�X�쵲��C���Ҧ��`�I\n(3)�p���C����\n(4)�[�J�@�s�`�I��S�w�`�I����\n(5)�[�J�@�s�`�I��S�w�`�I���e\n(6)�R���@�S�w�`�I\n(7)�N�C�`��C����\n(0)���� =>";
            cin>>choose;
                   
    switch(choose){
            case 0: 
                    loopflag=0;  
                    break;     
                      
            case 1:
             cout<<"�п�J���[�J���`�I��";
             int newvalue;
             cin>>newvalue;
             addNewNode(&head,newvalue);
             break;
             
             case 2:
             listAll(head);     
             break;
             case 3:
             cout<<"����C���׬�"<<lengthOfList(head)<<endl;    
             break;         
          case 4:
             
             cout<<"�п�J���j�M���`�I��";
             cin>>a;
             cout<<"�п�J���[�J���`�I��";
             cin>>b;
             insertAfter(head,a,b); 
             break;
             
          case 5:
             
             cout<<"�п�J���j�M���`�I��";
             cin>>a;
             cout<<"�п�J���[�J���`�I��";
             cin>>b;
             insertBefore(&head,a,b); 
             break;  
             
          
          case 6:
             
             cout<<"�п�J���R�����`�I��";
             cin>>a;
            
             deleteNode(&head,a); 
             break;
          case 7:
             reverse(&head);    
             break;
          case 8:
               ddelete(&head,head->rlink);
               break;
                 
           default:
                 cout<<"��J���~"<<endl;    
                 break;    
                          
             }
             
             cout<<endl; 
          
             }
    
    
    
    
   
    return 0;
    
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
     cout<<"�Ŧ�C"<<endl;
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
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;}
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     
     
     
     } 
     
     
     
void insertAfter(Node *p,int x,int y){
     Node *ptr=p;
     Node *pre;
     if(ptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
               
               
          }
     
     
     }  
     
     
     
void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *head=*ptr;
     if(*ptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     }
     
     
void reverse(Node **p){
     
     Node *head,*ptr,*tmp;
     tmp=*p;
     while(tmp->rlink!=*p)
     tmp=tmp->rlink;
     tmp->rlink=NULL;
     (*p)->llink=NULL;
     
     head=*p;
     ptr=head->rlink;
     while(head->rlink!=NULL){
      head->llink=ptr;
      head=head->rlink;                       
      ptr=ptr->rlink;       
                             }
      head->llink=NULL;
                             
     head=*p;
     ptr=head->llink;
     head->rlink=NULL;
     while(head->llink!=NULL){
          ptr->rlink=head;
          head=head->llink;
          ptr=ptr->llink;           
             }
     *p=head;
     while(head->rlink!=NULL)
        head=head->rlink;
        
        head->rlink=*p;
        (*p)->llink=head;
     
     }
     
     
     
void ddelete(Node **dlist,Node *p){
     
      if(p==(*dlist)){
                       
          if((*dlist)->rlink==*dlist){
                 *dlist=NULL;                   
                                    
                                    }             
       else{                
           *dlist=(*dlist)->rlink;
           p->llink->rlink=*dlist;
           (*dlist)->llink=p->llink;
           free(p);         
                    }
                    }
       else{
            
            p->rlink->llink=p->llink;
            p->llink->rlink=p->rlink;
                      
            } 
     
     
     }
     
