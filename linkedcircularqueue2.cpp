#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
     
        };      
 
void enqueue(Node **,int); 
void dequeue(Node **); 
void listAll(Node *);
void retrieve(Node *,int);
void delelement(Node **,int);      
       
int main(void){
   
      Node *tail=NULL; 
      
      enqueue(&tail,50);
      enqueue(&tail,65);
      enqueue(&tail,31);
      enqueue(&tail,24);
      enqueue(&tail,76);
      enqueue(&tail,98);
      listAll(tail); 
      dequeue(&tail);
      dequeue(&tail);
      dequeue(&tail);
      listAll(tail);                  
      enqueue(&tail,14);
      listAll(tail);
      dequeue(&tail);
      dequeue(&tail);
      listAll(tail);
      retrieve(tail,14);
      retrieve(tail,344);
      dequeue(&tail);
      dequeue(&tail);
      dequeue(&tail);
      retrieve(tail,14);
      delelement(&tail,50);
      enqueue(&tail,50);
      enqueue(&tail,65);
      enqueue(&tail,31);
      enqueue(&tail,24);
      enqueue(&tail,76);
      enqueue(&tail,98);
      delelement(&tail,500);
      listAll(tail);
      delelement(&tail,98);
      listAll(tail);
      delelement(&tail,50);
      listAll(tail);
      delelement(&tail,31);
      delelement(&tail,24);
      delelement(&tail,65);
      listAll(tail);
      delelement(&tail,76);
      delelement(&tail,76);
      
      
      system("pause");                      
      return 0;
    
}






void enqueue(Node **rear,int x){
     
     Node *newNode=new Node;
     newNode->data=x;
     if(*rear==NULL){
          *rear=newNode;
          (*rear)->link=*rear;             
          cout<<"Enqueue�i"<<x<<endl;              
                       }
     else{
          
           newNode->link=(*rear)->link;
          (*rear)->link=newNode;
           (*rear)=newNode;
         cout<<"Enqueue�i"<<x<<endl;    
          
          
          }
     
     
     }
     

void dequeue(Node **rear){
    if(*rear==NULL){
       cout<<"�Ŧ�C"<<endl;
       }
    else if((*rear)->link==*rear){
         int x=(*rear)->data;
         *rear=NULL;
        cout<<"Dequeue�X"<<x<<endl; 
         }
    else{
         Node *ptr=(*rear)->link;
         int x=ptr->data;
         (*rear)->link=ptr->link;
         free(ptr);
         cout<<"Dequeue�X"<<x<<endl; 
                                  
         }
    
    }
    
    
void listAll(Node *rear){
     
     Node *ptr;
     ptr=rear->link;
     
     do{
           cout<<ptr->data<<" ";               
           ptr=ptr->link;          
                    }while(ptr!=rear->link);
        
    cout<<endl;
    
     }
     
     
void retrieve(Node *rear,int x){
     if(rear==NULL)
         cout<<"�Ŧ�C!!"<<endl;           
     else{
         Node *ptr=rear;
         bool flag=false;
         
         do{
                      
             if(ptr->data==x)
                 flag=true;           
                              
             ptr=ptr->link;    
                                      
                           }while(ptr!=rear); 
          
          if(flag==true)
          cout<<"��줸��!!"<<endl;
          else
          cout<<"�S��줸��!!"<<endl; 
          
          
          }                    
     
     
     } 
     
     
void delelement(Node **rear,int x){
     int temp;
     if(*rear==NULL)
        cout<<"�Ŧ�C,�L�k�R��"<<endl;
     else if((*rear)->data==x&&(*rear)->link==(*rear)){
              temp=(*rear)->data;                                 
              *rear=NULL;
              cout<<"Dequeue�X"<<temp<<endl;                                
                                                } 
     else if((*rear)->data==x){
          Node *ptr=(*rear)->link;
          temp=(*rear)->data;
          
          while(ptr->link!=*rear)
          ptr=ptr->link;
          
          ptr->link=(*rear)->link;
          *rear=ptr;
          cout<<"Dequeue�X"<<temp<<endl;
          
          }  
      else{
           
           Node *ptr=(*rear)->link;
           Node *pre=*rear;
           while(ptr->data!=x&&ptr->link!=*rear){
              pre=ptr;
              ptr=ptr->link;}
           
           if(ptr->data==x){
                temp=ptr->data;            
                pre->link=ptr->link;
                ptr->link=NULL;
                 free(ptr);           
                cout<<"Dequeue�X"<<temp<<endl;           
                            }   
            else
                cout<<"�䤣��Ӹ`�I"<<endl;
              
           
           }
     
     }
