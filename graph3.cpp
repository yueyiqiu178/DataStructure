#include<iostream>
#define N 100
#define MIN(x,y) ((x)<(y)?(x):(y))

using namespace std;


struct Node{
        
     int data;   
     Node *link;
      
     
       
        };
      
struct Queue{
        int queuearray[N];
        int rear;
        int front;
        
        
        };  
        
struct Stack{
       int stackarrayA[N];
       int stackarrayB[N];
       int sp;
       
       
       };       

      
int low[10];      
int dfn[10];       
Node Adjlist[10];
bool visited[10];
Node *ptr;
bool flag=true;
int num;
Queue q;
Stack s;


void construct(Node*,int);
void DFS(int);
void queueMove(Queue *);
int isEmpty(Queue *);
void enQueue(Queue *,int);
void deQueue(Queue *,int *);
void createQueue(Queue *);
void BFS(int);
void connected();
void dfnlow(int,int);
void initial();
int push(Stack *,int);
int pop(Stack *);
int isempty(Stack *);
int isfull(Stack *);
void bicon(int,int);

int main(){
    
    createQueue(&q);
    
    for(int i=0;i<10;i++){
      Adjlist[i].link=NULL;
      Adjlist[i].data=i;}
      
    Node *head0=&Adjlist[0];
    Node *head1=&Adjlist[1];
    Node *head2=&Adjlist[2];
    Node *head3=&Adjlist[3];
    Node *head4=&Adjlist[4];
    Node *head5=&Adjlist[5];
    Node *head6=&Adjlist[6];
    Node *head7=&Adjlist[7];
    Node *head8=&Adjlist[8];
    Node *head9=&Adjlist[9];
    
    construct(head0,1);
    construct(head1,0);
    construct(head1,2);
    construct(head1,3);
    construct(head2,1);
    construct(head2,4);
    construct(head3,1);
    construct(head3,4);
    construct(head3,5);
    construct(head4,2);
    construct(head4,3);
    construct(head5,3);
    construct(head5,6);
    construct(head5,7);
    construct(head6,5);
    construct(head6,7);
    construct(head7,5);
    construct(head7,8);
    construct(head7,9);
    construct(head8,7);
    construct(head9,7);
    for(int i=0;i<10;i++)  
      visited[i]=false;
    
    
    //BFS(3);
    //connected();
    
    initial();
   // dfnlow(0,-1);
    
    bicon(4,-1);
    
    
    
    
    
    system("pause");
    return 0;
} 


void construct(Node* ptr,int x){
      Node *ppp=new Node;
      ppp->data=x;
      ppp->link=NULL;
      
      while(ptr->link!=NULL){
                             
        ptr=ptr->link;
       
     }
     ptr->link=ppp;
     
     }
     
     
void DFS(int v){
     Node *w;
     visited[v]=true;
     cout<<"Visit:"<<v<<endl;
     
     for(w=&Adjlist[v];w;w=w->link){
       if(!visited[w->data])
                 DFS(w->data);              
                                    
                                    }
     }
     
void BFS(int v){
     int temp;
     Node *w;
     cout<<"Visit:"<<v<<endl;
     visited[v]=true;
     enQueue(&q,v);
     while(!isEmpty(&q)){
         deQueue(&q,&temp);               
     for(w=&Adjlist[temp];w;w=w->link){
           if(!visited[w->data]){              
             cout<<"Visit:"<<w->data<<endl;                      
             enQueue(&q,w->data);
             visited[w->data]=true;                       
                                                        }     
                                    }
     
     
     }
     
     }
     
     
     
int isEmpty(Queue *p){
    if(p->rear==p->front)
    return 1;
    }
    
void enQueue(Queue *p,int x){
    if(p->rear==N-1)
     queueMove(p);
     
     
     p->rear++;
     p->queuearray[p->rear]=x;
     
     
     
     }
     
void deQueue(Queue *p,int *x){
 p->front++;
 *x=p->queuearray[p->front];
 
}
    
    

void queueMove(Queue *p){
     int i;
     for(i=p->front+1;i<=p->rear;i++)
     p->queuearray[i-p->front-1]=p->queuearray[i];
     p->rear=p->rear-p->front-1;
     p->front=-1;
     
     }
     
void createQueue(Queue *p){
     p->rear=-1;
     p->front=-1;
     }
     
     
void connected(){
     for(int i=0;i<10;i++){
       if(!visited[i])
        DFS(i);
        
     }
     
     
     }
     

void initial(){
     for(int i=0;i<10;i++){
       visited[i]=false;
       dfn[i]=-1;
       low[i]=-1;
     }
     
     num=0;
     
     }
     
     
void dfnlow(int u,int v){
     Node *ptr;
     int w;
     dfn[u]=low[u]=num++;
     for(ptr=&Adjlist[u];ptr;ptr=ptr->link){
       w=ptr->data;
       if(dfn[w]<0){
         dfnlow(w,u);
         low[u]=MIN(low[u],low[w]);           
                    }
     else if(w!=v)
     low[u]=MIN(low[u],dfn[w]);
     
     }
     
     }
     
     
int push(Stack *p,int x,int y){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarrayA[p->sp]=x;
     p->stackarrayB[p->sp]=y;
     
     }
     
int pop(Stack *p,int *x,int *y){
     if(isempty(p))
     return 1;
     else{
     *x=p->stackarrayA[p->sp];     
     *y=p->stackarrayB[p->sp];
     p->sp--;
     return 0;
     }
     } 

int isempty(Stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
     
int isfull(Stack *p){
    if(p->sp==N-1)   
    return 1;
    else
    return 0;   
}



void bicon(int u,int v){
     Node *ptr;
     int w,x,y;
     dfn[u]=low[u]=num++;
     for(ptr=&Adjlist[u];ptr;ptr=ptr->link){
        w=ptr->data;
        if(v!=w&&dfn[w]<dfn[u])
          push(&s,u,w);
          if(dfn[w]<0){
              bicon(w,u);         
              low[u]=MIN(low[u],low[w]);
              if(low[w]>=dfn[u]){
                      cout<<"新的雙連通單元:";
                      do{
                            pop(&s,&x,&y);
                            cout<<"<"<<x<<","<<y<<">";            
                                          
                                          }while(!((x==u)&&(y==w)));
                      
                                 cout<<endl;
                                 }         
                       }
                       else if(w!=v)
                       low[u]=MIN(low[u],dfn[w]);
     }
     
     }
