#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        };
        
struct queue{
       
     Node *rear;
     
       
       }; 
       
       
void initial(queue *); 
void enqueue(queue *,int); 
int dequeue(queue *); 
void listAll(queue *);
       
       
int main(void){
    
    queue q;
    initial(&q);
    
    int choose,loopflag=1;
    int data,tag;
    while(loopflag){
            
		cout << "\n(1)從佇列後端放資料\n(2)從佇列前端取資料\n(3)列出佇列中所有元素\n(0)結束 => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
             enqueue(&q,data); 
             break;
        case 2:
             tag=dequeue(&q);
			if(tag==0)
				cout << "佇列已空,Dequeue失敗"<<endl;
			else
            { 
                
                cout << "取出之資料為 => " <<tag<< endl;}
			break;
         case 3:
              listAll(&q);
              break;        
         default:
                 cout<<"輸入錯誤"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }  
           
      return 0;
    
}


void initial(queue *p){
     
    
     
     p->rear=NULL;
     
     
     }



void enqueue(queue *p,int x){
     
     Node *newNode=new Node;
     newNode->data=x;
     if(p->rear==NULL){
          p->rear=newNode;
          p->rear->link=p->rear;             
                       
                       }
     else{
          newNode->link=p->rear->link;
          p->rear->link=newNode;
          p->rear=newNode;
          
          
          }
     
     
     }
     

int dequeue(queue *p){
    if(p->rear==NULL){
       return 0;
       }
    else if(p->rear->link==p->rear){
         int x=p->rear->data;
         p->rear=NULL;
         return x;
         }
    else{
         Node *ptr=p->rear->link;
         int x=ptr->data;
         p->rear->link=ptr->link;
         free(ptr);
         return x;
         
         
         
         }
    
    }
    
    
void listAll(queue *p){
     
     Node *ptr;
    
     ptr=p->rear->link;
     while(ptr!=p->rear){
          cout<<ptr->data<<" ";               
          ptr=ptr->link;
                        
                         }
     cout<<ptr->data;                    
     cout<<endl;
     
     
     
     
     }
