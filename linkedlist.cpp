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
            
            cout<<"(1)插入一新節點\n(2)列出鏈結串列中所有節點\n(3)計算串列長度\n(4)加入一新節點於特定節點之後\n(5)加入一新節點於特定節點之前\n(6)刪除一特定節點\n(7)將鏈結串列反轉\n(8)搜尋一特定數值,若否則加入串列尾\n(0)結束 =>";
            cin>>selection;
                   
    switch(selection){
          case 0: control=0;  
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
             cout<<"反轉後的連結串列為: ";
             listAll(head);  
             break;          
          case 8:
               cout<<"請輸入要加入的節點值"<<endl;
               cin>>a;
               addone(&head,a);
               break;
          case 9:
               
               xx=head;
               yy=NULL;
               head=reverse_recur(head,NULL);
               break;
               
         default:
                 cout<<"輸入錯誤"<<endl;    
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
           cout<<"空串列,直接加入一新節點"<<endl;          
                      }
       else{
       Node *ptr=*head;
       while(ptr->data!=x&&ptr->link!=NULL)
          ptr=ptr->link;
       
       if(ptr->data==x)
         cout<<"找到節點"<<endl;
       else{
          Node *newNode=new Node;
          newNode->link=NULL;
          newNode->data=x;
          ptr->link=newNode;          
          cout<<"找不到該節點,加入一新結點於串列尾"<<endl;                       
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
     
     

