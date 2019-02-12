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

Node Adjlist[15];
bool visited[15];
Node *ptr;
int mark[15];
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
   
    
     for(int i=1;i<=14;i++){
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
    Node *head9=&Adjlist[9];
    Node *head10=&Adjlist[10];
    Node *head11=&Adjlist[11];
    Node *head12=&Adjlist[12];
    Node *head13=&Adjlist[13];
    Node *head14=&Adjlist[14];
    
    
    construct(head1,2);
    construct(head1,7);
    
    construct(head2,1);
    construct(head2,3);
    construct(head2,4);
    construct(head2,5);
    
    construct(head3,2);
    construct(head3,4);
    construct(head3,6);
    construct(head3,12);
    
    construct(head4,2);
    construct(head4,3);
    construct(head4,11);
    
    construct(head5,2);
    construct(head5,7);
    construct(head5,9);
    
    construct(head6,3);
    construct(head6,12);
    construct(head6,13);
    
    construct(head7,1);
    construct(head7,5);
    construct(head7,8);
    
    construct(head8,7);
    construct(head8,10);
    construct(head8,11);
    construct(head8,12);
    
    construct(head9,5);
    construct(head9,11);
    
    construct(head10,8);
    construct(head10,12);
    
    construct(head11,4);
    construct(head11,8);
    construct(head11,9);
    construct(head11,12);
    
    construct(head12,3);
    construct(head12,6);
    construct(head12,8);
    construct(head12,10);
    construct(head12,11);
    construct(head12,13);
    construct(head12,14);
    
    construct(head13,6);
    construct(head13,12);
    construct(head13,14);
    
    construct(head14,12);
    construct(head14,13);
    
        
     createQueue(&q);
     s.sp=-1;
     
     for(int i=1;i<=8;i++)  
      visited[i]=false;
      
       for(int i=1;i<=8;i++)  
        mark[i]=2;
      
    DFS(head13);
    
   
    
    
    
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
      int count=1;
      Node *Vx,*Vy;
      int before;
      bool tag=false;
      bool bitag=false;
      push(&s,ptr);
      while(!(isempty(&s))){
           
           pop(&s,Vx); 
                        
        if(visited[Vx->data]==false){
            cout<<"Visit:"<<Vx->data<<endl;
            visited[Vx->data]=true;
             mark[Vx->data]=(count++)%2;
             
             
             Vy=Adjlist[Vx->data].link;
             
             while(Vy!=NULL){
                             
                    if(mark[Vy->data]==mark[Vx->data]&&bitag==false){
                      cout<<"不是二分圖!!"<<endl;       
                      bitag=true;       
                             }
                    if(visited[Vy->data]==false){                    
                    push(&s,Vy);}
                    else{
                      if(Vy->data!=before&&tag==false){
                      cout<<"發現迴圈!!"<<endl;   
                      tag=true;
                      }
                         }
                    Vy=Vy->link;          
                                 }
                                              
                                 
                before=Vx->data;
                                 
                                 }
         
                               
                               }                  
                          
                          
                          
                          }
                          
                          
     
void BFS(Node *ptr){
     Node *Vx,*Vy;
      cout<<"Visit:"<<ptr->data<<endl;
      visited[ptr->data]=true;
     enQueue(&q,ptr);
     
     while(!isEmpty(&q)){
            deQueue(&q,Vx);
            
              Vy=Adjlist[Vx->data].link;
             
            while(Vy!=NULL){
                            
                    if(visited[Vy->data]==false){
                    cout<<"Visit:"<<Vy->data<<endl;
                    visited[Vy->data]=true;
                    cout<<"加入邊:("<<Vx->data<<","<<Vy->data<<")"<<endl;
                    enQueue(&q,Vy);}
                         
                    Vy=Vy->link;          
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


