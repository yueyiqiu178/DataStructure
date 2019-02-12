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
bool predecessor[9];
int mark[9];
bool flag=true;




void construct(Node*,int);

int push(stack *,Node*&);
void pop(stack *,Node*&);
int isempty(stack *);
int isfull(stack *);
void visit(Node*);
void DFS(Node*);
void BFS(Node *);
void createQueue(Queue *);
void queueMove(Queue *);
int isEmpty(Queue *);
void enQueue(Queue *,Node*&);
void deQueue(Queue *,Node*&);
void addEdge(Node *,Node *);
void checkConnectedDirection();

void checkConnectedUndirection(Node *);
void componentCount();
void checkCycleUndirection(Node *);
void checkCycleDirection(Node *);
void checkBipartite(Node *,int);
void DFS_recursive(Node *);



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
    construct(head2,3);
     
    construct(head2,6);
   
    
    
    construct(head3,4);
    construct(head3,6);
    construct(head4,1);
    construct(head5,2);
    construct(head5,4);
    construct(head6,1);
    construct(head6,5);
    
        
     createQueue(&q);
     s.sp=-1;
     
     for(int i=1;i<=8;i++)  
      visited[i]=false;
      
       for(int i=1;i<=8;i++)  
      predecessor[i]=false;
      
      for(int i=1;i<=8;i++)  
         mark[i]=0;
      
      //checkCycleDirection(head1);
    //checkConnectedUndirection(head7);
     //DFS(head3);
    
   // componentCount(head4);
   
    // checkBipart(head1);
     //cycle(head1);
     
   // checkBipartite(head2,1);
     DFS_recursive(head1);
    
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

     
     



void Mix(Node *ptr){
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
                          
                          
void DFS(Node *ptr){
      
      for(int i=1;i<=8;i++)  
       visited[i]=false;
      
      
      Node *Vx,*Vy;
      
      
      push(&s,ptr);
      while(!(isempty(&s))){
           
           pop(&s,Vx); 
                        
        if(visited[Vx->data]==false){
                                     
            cout<<"Visit:"<<Vx->data<<endl;
            visited[Vx->data]=true;
             
             
             
             Vy=Adjlist[Vx->data].link;
             
             while(Vy!=NULL){
                             
                   
                    if(visited[Vy->data]==false)                   
                    push(&s,Vy);
                    
                         
                    Vy=Vy->link;          
                                 }
                                                                              
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
    
    
void checkConnectedDirection(){
     
     bool tag=true;
     
     for(int i=1;i<=8;i++)
       visited[i]=false;
     
     for(int i=1;i<=8;i++){
       
        DFS(&Adjlist[i]);
        
        for(int i=1;i<=8;i++){
           if(visited[i]==false){
                tag=false;
                goto L1;
                }
                }
                
         for(int i=1;i<=8;i++)
           visited[i]=false;        
                
                
     }
     
     L1:
          if(tag==false)
           cout<<"此有向圖形不是connected"<<endl;
           else
           cout<<"此有向圖形是connected"<<endl;     
     
     
     }
     

void checkConnectedUndirection(Node *ptr){
     
       
        bool tag=true;
     
     for(int i=1;i<=8;i++)
       visited[i]=false;
     
        DFS(ptr);
        
        for(int i=1;i<=8;i++){
           if(visited[i]==false){ 
                tag=false;
                break;
                }                                              
             }     
     
           if(tag==false)
              cout<<"此無向圖形不是connected"<<endl;
           else
              cout<<"此無向圖形是connected"<<endl;  
     
     
     
     
     }



     
void componentCount(){
      
       int count=0;
       for(int i=1;i<=8;i++)
          visited[i]=false;
       
       for(int i=1;i<=8;i++){
               
               if(visited[i]==false){
                 DFS(&Adjlist[i]);
               count++;
               }
       
           
               }  
               
         cout<<"此圖形的連通組件有"<<count<<"個"<<endl;       
               
    }


void checkBipartOld(Node *ptr){
     
      int count=1;
      Node *Vx,*Vy;
      bool bitag=false;
      
       for(int i=1;i<=8;i++)  
        mark[i]=2;
      
      push(&s,ptr);
      mark[ptr->data]=count%2;
      count++;
      
      while(!(isempty(&s))){
           
           pop(&s,Vx); 
                        
        if(visited[Vx->data]==false){
            cout<<"Visit:"<<Vx->data<<endl;
            visited[Vx->data]=true;
            
            
             Vy=Adjlist[Vx->data].link;
             
             while(Vy!=NULL){
                    
                    if(visited[Vy->data]==false){                 
                    push(&s,Vy);
                    
                    int key=count%2;
                    
                    if(mark[Vy->data]!=2){ 
                       if(key!=mark[Vy->data])
                          cout<<"不是二分圖!!"<<endl;
                       } 
                    else{   
                    mark[Vy->data]=count%2;}
                    
                    
                                }
                    else if(visited[Vy->data]==true){            
                    if(mark[Vy->data]==mark[Vx->data]&&bitag==false){
                      cout<<"不是二分圖!!"<<endl;       
                      bitag=true;       
                             }
                             
                    
                    }
                         
                    Vy=Vy->link;          
                                 }// end while
                                 
                  count++;            
                                              
                                 }//end if
                                      
                               }//end while  
            if(bitag==false)
          cout<<"是二分圖!!!"<<endl;                       
                                                
     }



void checkCycleUndirection(Node *ptr){
     
      
      Node *Vx,*Vy;
     
      bool tag=false;
      
      push(&s,ptr);
      
      while(!(isempty(&s))){
           
           pop(&s,Vx); 
                        
        if(visited[Vx->data]==false){
            cout<<"Visit:"<<Vx->data<<endl;
            visited[Vx->data]=true;
            
             
             
             Vy=Adjlist[Vx->data].link;
             
             while(Vy!=NULL){
                             
                    
                    if(visited[Vy->data]==false){                    
                    push(&s,Vy);}
                    else{
                      if(visited[Vy->data]==true&&tag==false){
                      cout<<"發現迴圈!!"<<endl;   
                      tag=true;
                      }
                         }
                    Vy=Vy->link;          
                                 }
                                              
                                 
               
                                 
                                 }
         
                               
                               }                  
     }
     
     
void checkCycleDirectionOld(Node *ptr){
     
      
      Node *Vx,*Vy;
      
      bool tag=false;
      
      push(&s,ptr);
      
      while(!(isempty(&s))){
           
           pop(&s,Vx); 
                        
        if(visited[Vx->data]==false){
            cout<<"Visit:"<<Vx->data<<endl;
            visited[Vx->data]=true;
            predecessor[Vx->data]=true;
             
             
             Vy=Adjlist[Vx->data].link;
               if(Vy==NULL)
              predecessor[Vx->data]=false;
             
             while(Vy!=NULL){
                             
                    
                    if(visited[Vy->data]==false){                    
                    push(&s,Vy);}
                    else{
                      if(predecessor[Vy->data]==true&&tag==false){
                      cout<<"發現迴圈!!"<<endl;   
                      tag=true;
                      }
                         }
                    Vy=Vy->link;          
                                 }
                                                                  
                                 }
             
                        
                               
                               } 
                               
                               
                                                
     }
     
     
void checkCycleDirection(Node *ptr){
        
        Node *w;
        visited[ptr->data]=true;
        cout<<"Visit:"<<ptr->data<<endl;
        predecessor[ptr->data]=true;
        
        
        for(w=Adjlist[ptr->data].link;w;w=w->link){
           if(predecessor[w->data]==true)                                     
              cout<<"發現迴圈!!"<<endl;
           else if(visited[w->data]==false)
             checkCycleDirection(w);                                  
                                                    
               }
     
        predecessor[ptr->data]=false;
     
     
     
     }
     
     
     
void checkBipartite(Node *ptr,int key){
     
       
        Node *w;
        
        mark[ptr->data]=key;
        cout<<"Visit:"<<ptr->data<<endl;
       
        
        for(w=Adjlist[ptr->data].link;w;w=w->link){
           if(mark[w->data]==0)                                     
              checkBipartite(w,3-key);
            else if(mark[w->data]==mark[ptr->data])          
                cout<<"不是二分圖!!"<<endl;
                                                    
               }
     
     }
     
     
void DFS_recursive(Node *ptr){
      
      visited[ptr->data]=true;
      cout<<"Visit:"<<ptr->data<<" "<<endl;
      
      
      Node *w;
      for(w=Adjlist[ptr->data].link;w;w=w->link){
        
         if(visited[w->data]==false){
           cout<<"加入邊:("<<ptr->data<<","<<w->data<<")"<<endl;
           DFS_recursive(w);
           }
           
           }
           
     }


