#include<iostream>
#define N 100

using namespace std;


struct Node{
        
     int data;   
     Node *link;
      
     
       
        };
        
struct stack{
       Node* stackarray[N];
       int sp;
       
       
       };

stack s;        


struct Queue{
        Node* queuearray[N];
        int rear;
        int front;              
        };
        
Queue q;

Node Adjlist[9];
bool visited[9];
Node *ptr;
bool flag=true;



void printMessage();
void construct(Node*,int);
void DFSh(int);
int push(stack *,Node*&);
void pop(stack *,Node*&);
int isempty(stack *);
int isfull(stack *);
void visit(Node*);
Node* findAdj(Node *,int);
void DFS(Node*);
void BFS(Node *);
void createQueue(Queue *);
void queueMove(Queue *);
int isEmpty(Queue *);
void enQueue(Queue *,Node*&);
void deQueue(Queue *,Node*&);
void addEdge(Node *,Node *);
void connected();
void DFSre(Node *);
bool findCycle(Node *,Node *,int);
void DFSre2(Node *,Node *);


int main(void){
    for(int i=1;i<=8;i++){
      Adjlist[i].link=NULL;
      Adjlist[i].data=i;}
      
    Node *head1=&Adjlist[1];
    Node *head2=&Adjlist[2];
    Node *head3=&Adjlist[3];
    Node *head4=&Adjlist[4];
    Node *head5=&Adjlist[5];
    Node *head6=&Adjlist[6];
    Node *head7=&Adjlist[7];
    Node *head8=&Adjlist[8];
    
    construct(head1,2);
    construct(head1,3);
    construct(head2,1);
    construct(head2,3);
    construct(head2,4);
    construct(head2,5);
    construct(head3,1);
    construct(head3,2);
    construct(head3,6);
    construct(head3,7);
    construct(head4,2);
    construct(head4,5);
    construct(head4,8);
    construct(head5,2);
    construct(head5,4);
    construct(head6,3);
    construct(head7,3);
    construct(head8,4);
    
    createQueue(&q);
    s.sp=-1;
     for(int i=1;i<=8;i++)  
      visited[i]=false;
      
    // connected();
      
     int x;
     cout<<"請輸入起點";
     cin>>x;
      Node *p;
      switch(x){
         case 1:p=head1; break;       
         case 2:p=head2; break;
         case 3:p=head3; break;
         case 4:p=head4; break;
         case 5:p=head5; break;
         case 6:p=head6; break;
         case 7:p=head7; break;
         case 8:p=head8; break;
                }
      
      
    cout<<"DFS追蹤:"<<endl; 
    DFS(p);
    
    for(int i=1;i<=8;i++)  
      visited[i]=false;
    
    
    cout<<"BFS追蹤:"<<endl; 
    BFS(p);
    
    
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

     
     
void DFSh(int v){
      visited[v]=true;
     
      cout<<"Visit Vertex:"<<v<<" "<<endl;
      Node *w;
      for(w=&Adjlist[v];w;w=w->link)
        if(!visited[w->data])
           DFSh(w->data);
     }


void DFS(Node *ptr){
      
      Node *Vx,*Vy;
      
      push(&s,ptr);
      while(!(isempty(&s))){
           
           pop(&s,Vx);              
        if(visited[Vx->data]==false){
             visit(Vx);
             
             Vy=findAdj(&Adjlist[Vx->data],1);
             //addEdge(Vx,Vy);
                 while(Vy!=NULL){
                    push(&s,Vy);
                    
                    Vy=findAdj(&Adjlist[Vx->data],0);          
                                 }             
                                 
                                 
                                 }               
         else{if(flag)
                 printMessage();}
                               
                               }                  
                          
                          
                          
                          }
     
void BFS(Node *ptr){
     Node *Vx,*Vy;
     visit(ptr);
     enQueue(&q,ptr);
     while(!isEmpty(&q)){
            deQueue(&q,Vx);
            Vy=findAdj(&Adjlist[Vx->data],1);
                           
                while(Vy!=NULL){
                    visit(Vy);
                    addEdge(Vx,Vy);
                    enQueue(&q,Vy);      
                    Vy=findAdj(&Adjlist[Vx->data],0);          
                                 }                       
                         
                         
                         }
     
     
     
     
     }
     
void addEdge(Node *x,Node *y){
     cout<<"加入邊:("<<x->data<<","<<y->data<<")"<<endl;
     
     
     
     }     
     




void visit(Node *x){
     
      visited[x->data]=true;
      cout<<"Visit Vertex:"<<x->data<<" "<<endl;
     
     }
     
Node* findAdj(Node *head,int k){
       
       if(k==1)
         ptr=head->link;
       else
         ptr=ptr->link;
        
        
     while(ptr!=NULL){  
         if(visited[ptr->data]==false)
            return ptr;
          
          
            ptr=ptr->link;
          }
         
     return NULL;
     
     }  
     
     
     
int push(stack *p,Node* &x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
void pop(stack *p,Node *&x){
     
     x=p->stackarray[p->sp--];     
     
      
     } 
     
int isempty(stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
     
int isfull(stack *p){
    if(p->sp==N-1)   
    return 1;
    else
    return 0;   
}




void createQueue(Queue *p){
     p->rear=-1;
     p->front=-1;
     }
     
     
void enQueue(Queue *p,Node* &x){
    if(p->rear==N-1)
     queueMove(p);
     
     
     p->rear++;
     p->queuearray[p->rear]=x;
     
     
     
     }
void deQueue(Queue *p,Node* &x){
 p->front++;
 x=p->queuearray[p->front];

 
}

void queueMove(Queue *p){
     int i;
     for(i=p->front+1;i<=p->rear;i++)
     p->queuearray[i-p->front-1]=p->queuearray[i];
     p->rear=p->rear-p->front-1;
     p->front=-1;
     
     }

int isEmpty(Queue *p){
    if(p->rear==p->front)
    return 1;
    else
    return 0;
    }
    
void connected(){
     for(int i=1;i<=8;i++){
       if(!visited[i])
        DFS(&Adjlist[i]);
        
        cout<<endl;
     }
     
     
     }

void DFSre(Node *p){
     Node *Vx,*temp;
     visit(p);
     Vx=findAdj(&Adjlist[p->data],1);
     while(Vx!=NULL){
         temp=ptr;
         DFSre(Vx);
         ptr=temp;          
          Vx=findAdj(&Adjlist[p->data],0);         
                   
                   }

     }
     
     
     
void DFSre2(Node *p,Node *q){
     Node *Vx,*temp;
     visit(p);
     Vx=findAdj(&Adjlist[p->data],1);
    
     if(findCycle(p,q,1))
     cout<<"found "<<endl;
     
     q=p;
     p=Vx;
     
     while(Vx!=NULL){
         temp=ptr;
         DFSre2(p,q);
         ptr=temp;          
          Vx=findAdj(&Adjlist[p->data],0);         
                   
                   }

     }

bool findCycle(Node *current,Node *before,int k){
       
       if(k==1)
         ptr=current->link;
       else
         ptr=ptr->link;
        
        
     while(ptr!=NULL){  
         if(visited[ptr->data]==true&&(before==ptr))
            return true;
         
          
            ptr=ptr->link;
          }
         
   
     
     }
     
void printMessage(){
     flag=false;
     cout<<"此圖形含有至少一個cycle"<<endl;
     }


