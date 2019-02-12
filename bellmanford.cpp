#include<iostream>
#define INFINITE 20000
#define N 8

using namespace std;

int cost[N][N]={{0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,INFINITE,0,INFINITE,-1,INFINITE,INFINITE,INFINITE},
                {INFINITE,3,INFINITE,0,INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,3,INFINITE,INFINITE,0,INFINITE,INFINITE,INFINITE},
                {INFINITE,INFINITE,-2,1,INFINITE,0,-1,INFINITE},
                {INFINITE,INFINITE,INFINITE,-1,INFINITE,INFINITE,0,INFINITE},
                {INFINITE,INFINITE,5,INFINITE,INFINITE,3,3,0}
                 };


int dist[8];

void BellmanFord();

int main(void){
     
     for(int i=1;i<=7;i++)
       dist[i]=cost[7][i];
       
       for(int i=1;i<=7;i++){
        if(dist[i]==INFINITE)
        cout<<"# ";
        else
        cout<<dist[i]<<" ";
     
     }
      cout<<endl;
       
       
       BellmanFord();
     
     for(int i=1;i<=7;i++)
        cout<<dist[i]<<" ";
     
      
      cout<<endl;
      
    system("pause");
    return 0;
}


void BellmanFord(){
         
      int i,u,k;
      
      
      for(k=1;k<=N-2;k++){
       for(u=1;u<=N-1;u++){
         for(i=1;i<=N-1;i++){        
              
            if(dist[i]+cost[i][u]<dist[u])  
              dist[u]=dist[i]+cost[i][u];
              
              }
              }
              }
              
              
              }





    

