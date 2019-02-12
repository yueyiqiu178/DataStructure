#include<iostream>

using namespace std;


struct Node{
       
       int data;
       Node *llink;
       Node *rlink;
       
};


struct Queue{
        
        bool leftend; 
        Node *left;
        Node *right;
        
        };

 
void createQueue(Queue *); 
void insert(Queue *,int); 
void del(Queue *,int *);        
void queueList(Queue *);
       
int main(void)
{
    Queue q;
    createQueue(&q);
     
    int choose,loopflag=1;
    int data;
    while(loopflag){
            
		cout << "\n(1)從佇列左端放資料\n(2)從佇列右端放資料\n(3)從佇列左端取資料\n(4)從佇列右端取資料\n(5)列出佇列中所有元素\n(0)結束 => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
            
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
			 q.leftend=true;
             insert(&q,data); 
             break;
        case 2:   
             
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
			 q.leftend=false;
             insert(&q,data); 
             
             break;
        case 3:
			
                q.leftend=true;
                del(&q,&data);
                cout << "取出之資料為 => " <<data<< endl;
                
                break;
		case 4:
		
                q.leftend=false;
                del(&q,&data);
                cout << "取出之資料為 => " <<data<< endl;
			break;
         case 5:
              
              queueList(&q);
              break;
                      
         default:
                 cout<<"輸入錯誤"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }
    
    
    
    
     system("pause");
     return 0;
    
}



void createQueue(Queue *p){
     
     p->left=NULL;
     p->right=NULL;
     
     
     }
     
     
void insert(Queue *p,int x){
     Node *newNode=new Node;
     newNode->data=x;
     if(p->left==NULL){
     newNode->llink=NULL;
     newNode->rlink=NULL;
     p->left=newNode;
     p->right=newNode;    
     }
     else if(p->leftend==true){
     newNode->rlink=p->left;
     newNode->llink=NULL;
     p->left->llink=newNode;
     p->left=newNode;   
     }
     else{
       newNode->llink=p->right;
       newNode->rlink=NULL;
       p->right->rlink=newNode;
       p->right=newNode;   
          
          }                   
          }
          
void del(Queue *p,int *x){
     Node *ptr;
     if(p->left==NULL)
     cout<<"空佇列!!"<<endl;
     else if(p->left==p->right){
          ptr=p->left;
          *x=ptr->data;
          p->left=NULL;
          p->right=NULL;
          free(ptr);          
          } 
     else if(p->leftend==true){
          ptr=p->left;
          *x=ptr->data;
          p->left=p->left->rlink;
          p->left->llink=NULL;
          free(ptr);         
          }
     else{
          ptr=p->right;
          *x=ptr->data;
          p->right=p->right->llink;
          p->right->rlink=NULL;
          free(ptr);          
          }
     
     
     }
     
     
void queueList(Queue *p){
     Node *ptr=p->left;
     while(ptr!=NULL){
         cout<<ptr->data<<"  ";             
         ptr=ptr->rlink;
                      }
                      
            cout<<endl;          
     
     }
