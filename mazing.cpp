#include<iostream>

using namespace std;

typedef struct{
       int x[10000];
       int y[10000];
       int direction[10000];
       int sp;
       
       
       }stack;
stack s;

int xx[9]={0,-1,-1,0,1,1,1,0,-1};
int yy[9]={0,0,1,1,1,0,-1,-1,-1};


void createstack(stack *);
int push(stack *,int,int,int);
int pop(stack *);

int isempty(stack *);
int isfull(stack *);
void getitem(stack *,int *,int *,int *);
void writeDir(stack *,int);



int main(void)
{
    createstack(&s);
    int maze[14][14]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,0,1,0,0,1,0,1,0,0,1,0,1,1},
                      {1,0,0,0,1,1,0,0,1,1,0,1,0,1},
                      {1,1,0,0,0,1,0,1,0,0,1,0,1,1},
                      {1,0,1,1,1,1,1,0,1,1,1,1,0,1},
                      {1,0,1,0,1,0,0,0,1,0,1,0,0,1},
                      {1,1,0,1,1,1,0,1,0,0,1,1,1,1},
                      {1,0,1,0,0,1,1,0,1,1,0,1,1,1},
                      {1,0,1,1,1,1,0,1,0,1,1,0,0,1},
                      {1,1,0,1,1,0,1,0,0,0,0,1,0,1},
                      {1,0,1,0,0,1,1,1,0,1,1,0,1,1},
                      {1,0,1,1,1,0,1,1,0,1,1,0,1,1},
                      {1,1,0,1,0,0,0,1,1,0,0,1,0,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    
    int mark[14][14]={0};
    bool reach=false;
    mark[1][1]=1;
    maze[1][1]=2;
    push(&s,1,1,0);
    
    
    while(!isempty(&s)&&reach==false){
         
         int a,b,dir;               
          getitem(&s,&a,&b,&dir);              
            if(dir<8){
                                 
                int g,h;
                dir++;      
                g=a+xx[dir];      
                h=b+yy[dir];
                writeDir(&s,dir);      
                   if(maze[g][h]==0&&mark[g][h]==0){
                            maze[g][h]=2;                        
                            mark[g][h]=1;                        
                            push(&s,g,h,0);           
                             if(g==12&&h==12)                     
                               reach=true;    
                                                     
                                                    }   
                      
                      }
               else{
                    pop(&s);
                    }         
                        }
                        
        if(reach==true)    
          cout<<"Success"<< endl;
       else
          cout<<"Failed"<<endl;
    
       for(int i=0;i<14;i++){
         for(int j=0;j<14;j++){
            cout<<maze[i][j]<<" ";}
            cout<<endl;}
           
     system("pause");
       return 0;
}





void createstack(stack *p){
     p->sp=-1;
     } 
     



int push(stack *p,int x,int y,int dir){
     if(isfull(p))
     return 1;
     p->sp++;
     p->x[p->sp]=x;
     p->y[p->sp]=y;
     p->direction[p->sp]=dir;
     }
     
int pop(stack *p){
     if(isempty(p))
     return 1;
     else{
          p->sp--;
     return 0;     
     }
      
     } 
     
int isempty(stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
     
int isfull(stack *p){
    if(p->sp==9999)   
    return 1;
    else
    return 0;   
}


void getitem(stack *p,int *l,int *m,int *n){
     *l=p->x[p->sp];
     *m=p->y[p->sp];
     *n=p->direction[p->sp];
              
}


void writeDir(stack *p,int k){
     p->direction[p->sp]=k;
     
     
     
     }

