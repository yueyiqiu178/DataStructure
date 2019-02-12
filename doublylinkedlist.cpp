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
            
            cout<<"(1)插入一新節點\n(2)列出鏈結串列中所有節點\n(3)計算串列長度\n(4)加入一新節點於特定節點之後\n(5)加入一新節點於特定節點之前\n(6)刪除一特定節點\n(7)將列節串列反轉\n(0)結束 =>";
            cin>>choose;
                   
    switch(choose){
            case 0: 
                    loopflag=0;  
                    break;     
                      
            case 1:
             cout<<"請輸入欲加入的節點值";
             int newvalue;
             cin>>newvalue;
             addNewNode(&head,newvalue);
             break;
             case 2:
             listAll(head);     
             break; 
             case 3:
             cout<<"此串列長度為"<<lengthOfList(head)<<endl;    
             break;
             case 4:
             
             cout<<"請輸入欲搜尋之節點值";
             cin>>a;
             cout<<"請輸入欲加入之節點值";
             cin>>b;
             insertAfter(head,a,b); 
             break;
             
             case 5:
             
             cout<<"請輸入欲搜尋之節點值";
             cin>>a;
             cout<<"請輸入欲加入之節點值";
             cin>>b;
             insertBefore(&head,a,b); 
             break;
             case 6:
             
             cout<<"請輸入欲刪除之節點值";
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
        cout<<"此串列為空串列,找不到該節點"<<endl;
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
               cout<<"找不到該節點"<<endl; 
               
               
          }
     
     
     }

void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *newptr=*ptr;
     Node *k=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
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
               cout<<"找不到該節點"<<endl; 
                   
          }    
     }
     
  void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
       Node *s=(*ptr)->rlink;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
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
               cout<<"找不到該節點"<<endl; 
                   
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
     
