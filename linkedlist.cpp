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
void addone(Node **,int);
Node* reverse_recur(Node *,Node *);

int main(void){
    int i,x;
    int a,b;
    Node *head=NULL;
    Node *head2=NULL;
    Node *xx;
    Node *yy;
    int selection,option,control=1;
    
    while(control){ 
            
            cout<<"(1)���J�@�s�`�I\n(2)�C�X�쵲��C���Ҧ��`�I\n(3)�p���C����\n(4)�[�J�@�s�`�I��S�w�`�I����\n(5)�[�J�@�s�`�I��S�w�`�I���e\n(6)�R���@�S�w�`�I\n(7)�N�쵲��C����\n(8)�j�M�@�S�w�ƭ�,�Y�_�h�[�J��C��\n(0)���� =>";
            cin>>selection;
                   
    switch(selection){
          case 0: control=0;  
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
             cout<<"����᪺�s����C��: ";
             listAll(head);  
             break;          
          case 8:
               cout<<"�п�J�n�[�J���`�I��"<<endl;
               cin>>a;
               addone(&head,a);
               break;
          case 9:
               
               xx=head;
               yy=NULL;
               head=reverse_recur(head,NULL);
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
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
     else{
        while(ptr->data!=x&&ptr->link!=NULL) 
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
     Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     }
 
void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"����C���Ŧ�C,�䤣��Ӹ`�I"<<endl;
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
               cout<<"�䤣��Ӹ`�I"<<endl; 
                   
          }    
     
     
     
     }
 
     
     
void reverse(Node **head){
      Node *lead,*middle,*trail;
      lead=middle=(*head);
      trail=NULL;
      
      while(lead!=NULL){
           lead=lead->link;          
              middle->link=trail;
              trail=middle;
              middle=lead;
                            
                             }
       *head=trail;                    
      
     
     }
     
     
void addone(Node **head,int x){
       
       if(*head==NULL){
           Node *newNode=new Node;
          newNode->link=NULL;
          newNode->data=x;
          *head=newNode;
           cout<<"�Ŧ�C,�����[�J�@�s�`�I"<<endl;          
                      }
       else{
       Node *ptr=*head;
       while(ptr->data!=x&&ptr->link!=NULL)
          ptr=ptr->link;
       
       if(ptr->data==x)
         cout<<"���`�I"<<endl;
       else{
          Node *newNode=new Node;
          newNode->link=NULL;
          newNode->data=x;
          ptr->link=newNode;          
          cout<<"�䤣��Ӹ`�I,�[�J�@�s���I���C��"<<endl;                       
            }
     
     }
     
     }


Node* reverse_recur(Node *x,Node *y){
      
       
       if(x==NULL)
          return y;
          
       else{
            
           Node *temp;
           
           temp=reverse_recur(x->link,x);
           x->link=y;  
           return temp;  
           
            
            }     
     }
     
     

