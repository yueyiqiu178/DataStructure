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
        
int main(void){
    Node *head=NULL;
    Node *head2=NULL;
    int loopflag,choose;
    int a,b;
     while(loopflag){ 
            
            cout<<"(1)���J�@�s�`�I\n(2)�C�X�쵲��C���Ҧ��`�I\n(3)�p���C����\n(4)�[�J�@�s�`�I��S�w�`�I����\n(5)�[�J�@�s�`�I��S�w�`�I���e\n(6)�R���@�S�w�`�I\n(7)�N�C�`��C����\n(8)�ƻs�쵲��C\n(9)�C�X�s��C�Ҧ��`�I\n(0)���� =>";
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
             cout<<"����C���׬�"<<length(head)<<endl;    
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
             cout<<"����᪺�s����C��: ";
             listAll(head);
             break;
             
          case 8:
               
               copy(head,&head2);   
                break;
          case 9:
               listAll(head2);      
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
      cout<<"�Ŧ�C"<<endl;
      else{
           
         do{
             cout<<pTail->data<<"  ";
             pTail=pTail->link;   
                           
                           }while(pTail!=ptr);
         
         }
     

     
     }
     
int length(Node *ptr){
     int count=0;
     Node *lkk=ptr;
     if(ptr==NULL)
     return 0;
     else{
      
      do{
          count++;
          lkk=lkk->link;
          
          }while(lkk!=ptr);
      
          
    
     return count;
     }
     }
     
     
void insertAfter(Node *ptr,int x,int y){
     
     if(ptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
     else{
        while(ptr->data!=x&&ptr->link!=ptr) 
          ptr=ptr->link;
          
          if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=ptr->link;
          ptr->link=pNewNode;}
          else
               cout<<"�䤣��Ӹ`�I"<<endl; 
               
               
          }
     
     
     }
     
     
void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *head=*ptr;
     Node *temp=*ptr;
     if(*ptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     }
     
     
void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
       Node *pTail=*ptr;
     if(newptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     
     
     
     }
 
     
     
void reverse(Node **head){
      Node *p,*q,*r;
      q=NULL;
      p=*head;
      
      do{
          
          r=p->link;
          p->link=q;
          q=p;
          p=r;
          
              
              
              }while(p!=(*head));
        
        p->link=q;    
              
        *head=q;      
      
      
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

