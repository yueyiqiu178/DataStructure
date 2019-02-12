#include<iostream>
#define N 10
using namespace std;

struct Queue{
        int queuearray[N];
        bool leftend;
        int left;
        int right;
        };
        
void createQueue(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void enQueue(Queue *,int *);
void deQueue(Queue *,int *);
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
             if(isFull(&q)){
             cout<<"佇列已滿,Enqueue失敗"<<endl;
             break;}
             else{
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
			 q.leftend=true;
             enQueue(&q,&data); 
             break;}
        case 2:   
             if(isFull(&q)){
             cout<<"佇列已滿,Enqueue失敗"<<endl;
             break;}
             else{
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
			 q.leftend=false;
             enQueue(&q,&data); 
             break;}
             
        case 3:
			if(isEmpty(&q))
				cout << "佇列已空,Dequeue失敗"<<endl;
			else
            { 
                q.leftend=true;
                deQueue(&q,&data);
                cout << "取出之資料為 => " <<data<< endl;
                }
            break;    
		case 4:
			if(isEmpty(&q))
				cout << "佇列已空,Dequeue失敗"<<endl;
			else
            { 
                q.leftend=false;
                deQueue(&q,&data);
                cout << "取出之資料為 => " <<data<< endl;}
			break;
         case 5:
              queueList(&q);
              break; 
         case 6:cout<<q.queuearray[0]<<" "<<q.queuearray[9]<<" "<<q.queuearray[8]<<endl; 
              break;
         default:
                 cout<<"輸入錯誤"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }
    
    
    
   
    
    return 0;
}

void createQueue(Queue *p){
     
     p->right=0;
     p->left=1;
     }
     
int isFull(Queue *p){
 if((p->right+2)%N==p->left)
 return 1;
 else
 return 0;
    
}

int isEmpty(Queue *p){
    if((p->right+1)%N==p->left)
    return 1;
    else
    return 0;
    }
    
void enQueue(Queue *p,int *x){
   
     
     if(p->leftend){
        p->left=(p->left-1+N)%N;
        p->queuearray[p->left]=*x;}
     else{
        p->right=(p->right+1)%N;
        p->queuearray[p->right]=*x;
          }
     
     }
     
void deQueue(Queue *p,int *x){
      if(p->leftend){
          *x=p->queuearray[p->left];
          p->left=(p->left+1)%N;            
                }
      else{
           *x=p->queuearray[p->right];
           p->right=(p->right-1+N)%N;
}
}     
     

void queueList(Queue *p){
     
     if(isEmpty(p))
     cout<<"佇列中沒有資料"<<endl;
     else{
     int i;
     for(i=p->left%N;i!=p->right;i=(i+1)%N)
     cout<<p->queuearray[i]<<"  ";
     
     cout<<p->queuearray[p->right]<<endl;
     }
     
     
     }
