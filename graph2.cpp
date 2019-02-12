#include<iostream>
#define N 100

using namespace std;

struct stack{
       int stackarray[N];
       int sp;
       
       
       };

stack s;

int col;
int visited[8];

int a[8][8]={{0,1,1,0,0,0,0,0},
            {1,0,0,1,1,0,0,0},
            {1,0,0,0,0,1,1,0},
            {0,1,0,0,0,0,0,1},
            {0,1,0,0,0,0,0,1},
            {0,0,1,0,0,0,0,1},
            {0,0,1,0,0,0,0,1},
            {0,0,0,1,1,1,1,0}};
    


int push(stack *,int);
int pop(stack *);
int isempty(stack *);
int isfull(stack *);
void visit(int);
int findAdj(int,int);
void DFS(int);
void DFSre(int);

int main(void){
    s.sp=-1;
    for(int i=0;i<8;i++)
       visited[i]=0;
    
    DFS(0);
    
    
    
    system("pause");
    return 0;
}





int push(stack *p,int x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
int pop(stack *p){
     if(isempty(p))
     return 1;
     else
     return p->stackarray[p->sp--];     
     
      
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




void DFS(int v){
     int Vx,Vy;
     
     push(&s,v);
     
     while(!isempty(&s))
     {
        Vx=pop(&s);          
        if(visited[Vx]==0)
        {          
             visit(Vx);           
             
             Vy=findAdj(Vx,1);
                    while(Vy!=-1)
                    {
                       push(&s,Vy);        
                       Vy=findAdj(Vx,0);        
                               
                    }     
        }
                  
     }
}



void DFSre(int v){
     int Vx,temp;
     visit(v);
     Vx=findAdj(v,1);
     while(Vx!=-1){
         temp=col;
         DFSre(Vx);
         col=temp;          
          Vx=findAdj(v,0);         
                   
                   
                   }
     
     
     }
     
     
void visit(int x){
     visited[x]=1;
     cout<<"Visit Vertex:"<<x<<" "<<endl;
     
     
     }
     
     
int findAdj(int v,int first){
     if(first==1)
        col=0;
      else
        col++;    
    while(col<8){
         if(a[v][col]==0||visited[col]==1)        
              col++;
         else
            return col;
            }
    
    
    return -1;
    
}

