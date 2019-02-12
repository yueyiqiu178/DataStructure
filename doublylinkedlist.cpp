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
     (*ptr)=pNewNode;}
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->rlink!=NULL){
     pTailNode=pTailNode->rlink;
     }
     pTailNode->rlink=pNewNode;
     pNewNode->rlink=NULL;
     pNewNode->llink=pTailNode;
     }
     }
     
     
void listAll(Node *ptr){
     while(ptr!=NULL){ 
     cout<<ptr->data<<"  ";
     ptr=ptr->rlink;
     } 
      
      
}



      
     
int lengthOfList(Node *ptr){
    int count=0;
    if(ptr==NULL)
    return 0;
    else{
    while(ptr!=NULL) {
     count++;
     ptr=ptr->rlink;
     }
     
     return count;
     }
     }
     
     
     
void insertAfter(Node *ptr,int x,int y){
     Node *r=ptr->rlink;
     if(ptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
     else{
        while(ptr->data!=x&&r->rlink!=NULL) {
          ptr=ptr->rlink;
          r=r->rlink;}
          if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=ptr->rlink;
          pNewNode->llink=ptr;
          ptr->rlink->llink=pNewNode;
          ptr->rlink=pNewNode;}
          else if(r->data==x){
               Node *pNewNode=new Node;
               pNewNode->data=y;
               pNewNode->rlink=NULL;
               pNewNode->llink=r;
               r->rlink=pNewNode;
               }
          else
               cout<<"�䤣��Ӹ`�I"<<endl; 
               
               
          }
     
     
     }

void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *newptr=*ptr;
     Node *k=*ptr;
     if(newptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
     else if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=newptr;
          pNewNode->llink=NULL;
          newptr->llink=pNewNode;
          *ptr=pNewNode;
          
          }
     else{
        while(k->data!=x&&k->rlink!=NULL){ 
          r=k;
          k=k->rlink;}
          
          if(k->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=k;
          pNewNode->llink=r;
          r->rlink=pNewNode;
          r->llink=pNewNode;
          }
          else
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     }
     
  void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
       Node *s=(*ptr)->rlink;
     if(newptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
     else if(newptr->data==x){
          
          (*ptr)=(*ptr)->rlink;
           (*ptr)->llink=NULL;       
          }   
     else{
        while(newptr->data!=x&&s->rlink!=NULL){ 
             r=newptr;
             newptr=newptr->rlink;
             s=s->rlink;
          }
          
          if(newptr->data==x){
            r->rlink=newptr->rlink;
            newptr->rlink->llink=r;
            newptr->rlink==NULL;
            newptr->llink==NULL;
          }
          else if(s->data==x){
            s->llink==NULL;
            newptr->rlink=NULL;   
               
               }
          else
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     
     
     
     }   
     
     
void reverse(Node **p){
     
     Node *head,*ptr;
     
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
     
     }
     
