#include<iostream>
#define INFINITE 20000

using namespace std;

int cost[9][9]={{0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,300,0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,1000,800,0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,INFINITE,INFINITE,1200,0,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,INFINITE,INFINITE,INFINITE,1500,0,250,INFINITE,INFINITE},
                {INFINITE,INFINITE,INFINITE,INFINITE,1000,INFINITE,0,900,1400},
                {INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,0,1000},
                {INFINITE,1700,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,0},
                 };
int dist[9];
int pred[9];
int s[9];


void findmin(int *);
void dijkstra(int);
void printPath(int,int);
int exitt();


int main(void){
      int x;
      cout<<"請輸入起點";
      cin>>x;
      

      dijkstra(x);
                           
      for(int i=1;i<=8;i++){
              if(i==x)
              continue;
          cout<<"V"<<x<<"到V"<<i<<"成本為"<<dist[i]<<endl;
         printPath(x,i); 
         cout<<endl;
      } 
           
     

    system("pause");
    return 0;
}




void dijkstra(int v){
     int Vx;
     
     for(int i=1;i<=8;i++){
       dist[i]=cost[v][i];
       s[i]=0;
       
       if(cost[v][i]==0)
       pred[i]=0;
       else if(cost[v][i]!=INFINITE)
       pred[i]=v;
       else
       pred[i]=0; 
      }
      
      for(int i=1;i<=8;i++)
       cout<<pred[i]<<" ";
      
      cout<<endl;
      s[v]=1; 
      
      for(int i=1;i<=7;i++){
         findmin(&Vx);
         s[Vx]=1;
      for(int j=1;j<=8;j++){
         if(s[j]==0&&dist[j]>dist[Vx]+cost[Vx][j]){   
         dist[j]=dist[Vx]+cost[Vx][j];
         pred[j]=Vx;
      }
      
      }
      }
      
      
      
      
     }
     
     
void findmin(int *p){
     int k;
     int lowest=INFINITE;
    
     for(int i=1;i<=8;i++){
         if((dist[i]<lowest)&&(s[i]==0)){
           lowest=dist[i];
           k=i; 
         }
     }
     
     *p=k;
     
     
     }
     
void printPath(int V0,int Vx){
     cout<<"V"<<V0<<"到V"<<Vx<<"的路徑為:"; 
     
     cout<<Vx<<" ";
     
     int i=pred[Vx];
     
     while(i!=0){
     cout<<i<<" ";
     i=pred[i];
     
     }
    
     cout<<endl;
     
     }  
    

