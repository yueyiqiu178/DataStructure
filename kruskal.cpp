#include<iostream>


using namespace std;

struct edge{
      int Vx; 
      int Vy;
      int cost;
      int selected;
       
       
       };

edge E[11];
int vertex[8];
int TotalCost=0;


void buildGraph();
int selectEdge();
void kruskal();
int findRoot(int);
void addEdge(int);
int cycle(int);
void print(int);


int main(void){
    for(int i=1;i<=7;i++)
        vertex[i]=-1;
        
        
     buildGraph();
     kruskal();
    
     for(int i=1;i<=7;i++)
        cout<<vertex[i]<<" ";
       cout<<endl; 
    
    system("pause");
    return 0;
}


void buildGraph(){
      E[1].Vx=1;
      E[1].Vy=6;
      E[1].cost=56;
      E[1].selected=0;
      E[2].Vx=1;
      E[2].Vy=2;
      E[2].cost=20;
      E[2].selected=0;
      E[3].Vx=6;
      E[3].Vy=7;
      E[3].cost=10;
      E[3].selected=0;
      E[4].Vx=5;
      E[4].Vy=6;
      E[4].cost=24;
      E[4].selected=0;
      E[5].Vx=2;
      E[5].Vy=3;
      E[5].cost=40;
      E[5].selected=0;
      E[6].Vx=5;
      E[6].Vy=7;
      E[6].cost=8;
      E[6].selected=0;
      E[7].Vx=4;
      E[7].Vy=5;
      E[7].cost=7;
      E[7].selected=0;
      E[8].Vx=4;
      E[8].Vy=7;
      E[8].cost=3;
      E[8].selected=0;
      E[9].Vx=3;
      E[9].Vy=4;
      E[9].cost=35;
      E[9].selected=0;
      E[10].Vx=2;
      E[10].Vy=7;
      E[10].cost=32;
      E[10].selected=0;  
     }
     
void kruskal(){
     int ex;
     int counter=1;
     while(counter<=6){
     
     ex=selectEdge();
     if(!(cycle(ex))){
         addEdge(ex);
         counter++;
         print(ex);           
                    }
     else
         E[ex].selected=2;
     
     }
     
     
     cout << "Totol Cost is : " << TotalCost <<endl;
     
     }
     
     
int selectEdge(){
     int costmin=10000;
     int choose;
     for(int i=1;i<=10;i++){
        if((E[i].cost<costmin)&&(E[i].selected==0)){
                 costmin=E[i].cost;                                   
                 choose=i;  }
             }
     return choose;
     
     
     }
     
     
int findRoot(int w){
    
     while(vertex[w]>0)
       w=vertex[w];
      
     return w;
     }
     
     
int cycle(int x){
     int i,j;
     i=findRoot(E[x].Vx);
     j=findRoot(E[x].Vy);
     
     if(i==j)
       return 1;
     else
       return 0;
     
     }
     
void addEdge(int e){
     int i,j,temp;
     E[e].selected=1;
     i=findRoot(E[e].Vx);
     j=findRoot(E[e].Vy);
     
     if(vertex[i]<vertex[j]){
      vertex[i]=vertex[i]+vertex[j];     
      vertex[j]=i;
     }
     
     else if(vertex[j]<vertex[i]){
          
      vertex[j]=vertex[j]+vertex[i];     
      vertex[i]=j;    
          
          }
          
     else{
         
         vertex[j]=vertex[j]+vertex[i];   
         vertex[i]=j;  
          
          }
     
     
     }
                 
void print(int e){
     
     if(E[e].selected==1){
		cout << "V" << E[e].Vx << ",V" << E[e].Vy << " selected, cost=" << E[e].cost <<endl;
		TotalCost = TotalCost+E[e].cost;
	}
     
     
     
     
     }
