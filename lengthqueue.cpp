#include<iostream>
#define N 5
using namespace std;

struct Queue{
        int queuearray[N];
        int front;
        int length;
        
        
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
    int k,y;
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
    
    
    
   getchar(); 
    
    return 0;
}

void createQueue(Queue *p){
     p->length=0;
     p->front=0;
     }
     
int isFull(Queue *p){
 if(p->length==N)
 return 1;
    
}

int isEmpty(Queue *p){
    if(p->length==0)
    return 1;
    }
    
void enQueue(Queue *p,int *x){
   
     p->queuearray[(p->front+p->length)%N]=*x;
     p->length++;
     
     }
     
     
void deQueue(Queue *p,int *x){

 *x=p->queuearray[p->front];
 p->front=(p->front+1)%N;
 p->length--;
 
 
}
     
     

     
void queueList(Queue *p){
    int i,j;
     
     for (i=p->front,j=1;j<=p->length;i=(i+1)%N,j++ )
        cout<<p->queuearray[i]<<"  ";
     
     
     cout<<endl;
     
     
     }
