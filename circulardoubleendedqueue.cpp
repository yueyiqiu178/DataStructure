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
            
		cout << "\n(1)�q��C���ݩ���\n(2)�q��C�k�ݩ���\n(3)�q��C���ݨ����\n(4)�q��C�k�ݨ����\n(5)�C�X��C���Ҧ�����\n(0)���� => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             if(isFull(&q)){
             cout<<"��C�w��,Enqueue����"<<endl;
             break;}
             else{
             cout << "�п�J����J�����=> ";
			 cin >> data;
			 q.leftend=true;
             enQueue(&q,&data); 
             break;}
        case 2:   
             if(isFull(&q)){
             cout<<"��C�w��,Enqueue����"<<endl;
             break;}
             else{
             cout << "�п�J����J�����=> ";
			 cin >> data;
			 q.leftend=false;
             enQueue(&q,&data); 
             break;}
             
        case 3:
			if(isEmpty(&q))
				cout << "��C�w��,Dequeue����"<<endl;
			else
            { 
                q.leftend=true;
                deQueue(&q,&data);
                cout << "���X����Ƭ� => " <<data<< endl;
                }
            break;    
		case 4:
			if(isEmpty(&q))
				cout << "��C�w��,Dequeue����"<<endl;
			else
            { 
                q.leftend=false;
                deQueue(&q,&data);
                cout << "���X����Ƭ� => " <<data<< endl;}
			break;
         case 5:
              queueList(&q);
              break; 
         case 6:cout<<q.queuearray[0]<<" "<<q.queuearray[9]<<" "<<q.queuearray[8]<<endl; 
              break;
         default:
                 cout<<"��J���~"<<endl;    
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
     cout<<"��C���S�����"<<endl;
     else{
     int i;
     for(i=p->left%N;i!=p->right;i=(i+1)%N)
     cout<<p->queuearray[i]<<"  ";
     
     cout<<p->queuearray[p->right]<<endl;
     }
     
     
     }
