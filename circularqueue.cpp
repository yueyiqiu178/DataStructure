#include<iostream>
#define N 5
using namespace std;

typedef struct{
        int queuearray[N];
        int rear;
        int front;
        
        
        }queue;
void createQueue(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enQueue(queue *,int *);
void deQueue(queue *,int *);
void queueList(queue *);
void delItem(queue *,int *,int);
void addItem(queue *p,int ,int );


int main(void)
{
    queue q;
    createQueue(&q);
    
    int choose,loopflag=1;
    int data;
    int k,y;
    while(loopflag){
            
		cout << "\n(1)從佇列後端放資料\n(2)從佇列前端取資料\n(3)列出佇列中所有元素\n(4)刪除佇列中第K個元素\n(5)在佇列第K個位置之後加入一元素\n(0)結束 => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             if(isFull(&q)){
             cout<<"佇列已滿,Enqueue失敗"<<endl;
             break;}
             else
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
             enQueue(&q,&data); 
             break;
        case 2:
			if(isEmpty(&q))
				cout << "佇列已空,Dequeue失敗"<<endl;
			else
            { 
                deQueue(&q,&data);
                cout << "取出之資料為 => " <<data<< endl;}
			break;
         case 3:
              queueList(&q);
              break;
              
         case 4:
               cout<<"請輸入要刪除第幾個元素";
               cin>>k;
               
               if(k>(((q.rear-q.front)+N)%N))
               cout<<"有錯誤,做不出來"<<endl; 
               else{
               delItem(&q,&data,k);
               cout << "被刪除的資料為 => " <<data<< endl;
               }
               break;
          case 5:
               if(isFull(&q))
               cout<<"佇列已滿,加入失敗";
               else{
               cout<<"請輸入要在第幾個元素之後加入";
               cin>>k;
               if(k>(((q.rear-q.front)+N)%N))
               cout<<"有錯誤,做不出來"<<endl; 
               cout<<"請輸入要插入之元素";
               cin>>y;
               addItem(&q,y,k);
                    
               }
               break;
         default:
                 cout<<"輸入錯誤"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }
    
    
    
   getchar(); 
    
    return 0;
}

void createQueue(queue *p){
     p->rear=N-1;
     p->front=N-1;
     }
     
int isFull(queue *p){
 if((p->rear+1)%N==p->front)
 return 1;
    
}

int isEmpty(queue *p){
    if(p->rear==p->front)
    return 1;
    }
    
void enQueue(queue *p,int *x){
    p->rear=(p->rear+1)%N;
     p->queuearray[p->rear]=*x;
     
     }
     
void deQueue(queue *p,int *x){
p->front=(p->front+1)%N;
 *x=p->queuearray[p->front];
 
}
     
     

     
void queueList(queue *p){
    int i;
     
     for (i=(p->front+1)%N; i!= p->rear ;i=(i+1)%N )
        cout<<p->queuearray[i]<<"  ";
     
     
     cout<<p->queuearray[p->rear]<<endl;
     
     
     }
     
void delItem(queue *p,int *x,int k){
     int i;
     
     
     
     i=(p->front+k)%N;
     *x=p->queuearray[i];
     
     while(i!=p->rear){
           p->queuearray[i]=p->queuearray[(i+1)%N];            
          i=(i+1)%N;             
                       }
                       
          p->rear=(p->rear-1+N)%N;
     }
     
void addItem(queue *p,int y,int k){
     int i=p->rear;
     while(i!=(p->front+k)%N){
     p->queuearray[(i+1)%N]=p->queuearray[i];
     i=(i-1+N)%N;     
     }
     p->queuearray[(i+1)%N]=y;
     p->rear=(p->rear+1)%N;
     }
