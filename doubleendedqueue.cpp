#include<iostream>
#define N 6
using namespace std;

typedef struct{
        int queuearray[N];
        bool leftend;
        int left;
        int right;
        
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
             }
             break;
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
         default:
                 cout<<"輸入錯誤"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }
    
    
    
   
    
    return 0;
}

void createQueue(queue *p){
     
     p->right=(N-1)/2;
     p->left=p->right+1; 
     }
     
int isFull(queue *p){
 if(p->left==0&&p->right==N-1)
 return 1;
    
}

int isEmpty(queue *p){
    if(p->left>p->right)
    return 1;
    }
    
void enQueue(queue *p,int *x){
    if((p->leftend&&p->left==0)||(!p->leftend&&p->right==N-1))
     queueMove(p);
     
     if(p->leftend){
        p->left--; 
        p->queuearray[p->left]=*x;}
     else{
        p->right++;
        p->queuearray[p->right]=*x;
          }
     
     }
     
void deQueue(queue *p,int *x){
      if(p->leftend){
          *x=p->queuearray[p->left];
          p->left++;            
                }
      else{
           *x=p->queuearray[p->right];
           p->right--;
}
}     
     
void queueMove(queue *p){
    int i;
    
    if(p->left==0){
     for(i=p->right;i>=p->left;i--)
        p->queuearray[i+1]=p->queuearray[i];
     p->left++;
     p->right++;
     }
     else if(p->right==N-1){
          for(i=p->left;i<=p->right;i++)
          p->queuearray[i-1]=p->queuearray[i];
          p->left--;
          p->right--;
          
          }
          
          
}    
void queueList(queue *p){
     int i;
     for(i=p->left;i<=p->right;i++)
     cout<<p->queuearray[i]<<"  ";
     
     cout<<endl;
     }
