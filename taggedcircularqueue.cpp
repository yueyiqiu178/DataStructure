#include<iostream>
#define N 5
using namespace std;

typedef struct{
        int queuearray[N];
        int rear;
        int front;
        bool Qfull;
        
        }queue;
void createQueue(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enQueue(queue *,int *);
void deQueue(queue *,int *);
void queueMove(queue *);
void queueList(queue *);

int main(void)
{
    queue q;
    createQueue(&q);
    
    int choose,loopflag=1;
    int data;
    while(loopflag){
            
		cout << "\n(1)�q��C��ݩ���\n(2)�q��C�e�ݨ����\n(3)�C�X��C���Ҧ�����\n(0)���� => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             if(isFull(&q)){
             cout<<"��C�w��,Enqueue����"<<endl;
             break;}
             else
             cout << "�п�J����J�����=> ";
			 cin >> data;
             enQueue(&q,&data); 
             break;
        case 2:
			if(isEmpty(&q))
				cout << "��C�w��,Dequeue����"<<endl;
			else
            { 
                deQueue(&q,&data);
                cout << "���X����Ƭ� => " <<data<< endl;}
			break;
         case 3:
              queueList(&q);
              break;        
         default:
                 cout<<"��J���~"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }
    
    
    
   
    
    return 0;
}

void createQueue(queue *p){
     p->rear=N-1;
     p->front=N-1;
     p->Qfull=false;
     }
     
int isFull(queue *p){
 
 if(p->Qfull)
 return 1;
    
}

int isEmpty(queue *p){
    if(!p->Qfull&&p->rear==p->front)
    return 1;
    }
    
void enQueue(queue *p,int *x){
    p->rear=(p->rear+1)%N;
     p->queuearray[p->rear]=*x;
     
     if(p->rear==p->front)
     p->Qfull=true;
     }
     
void deQueue(queue *p,int *x){
p->front=(p->front+1)%N;
 *x=p->queuearray[p->front];
 p->Qfull=false;
 
}
     
     

     
void queueList(queue *p){
     int i;
     
     for (i=(p->front+1)%N; i!= p->rear ;i=(i+1)%N )
        cout<<p->queuearray[i]<<"  ";
     
     
     cout<<p->queuearray[p->rear]<<endl;
     }
